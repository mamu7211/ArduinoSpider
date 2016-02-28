using SharpDX.XInput;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Threading;

namespace SpiderController
{
    public partial class Form1 : Form
    {
        Controller _controller;
        DispatcherTimer _timer;
        int _height = 0;
        int _roll = 0;
        int _prevRoll = 0;
        int _prevHeight = 0;
        bool _canSend = true;

        string[] serialPortNames
        {
            get {
                return SerialPort.GetPortNames();
            }
        }

        public Form1()
        {
            InitializeComponent();
            fillPortList();
            connectController();
            setupTimer();
            updateView();
        }

        private void updateView()
        {
            if (_controller == null || !_controller.IsConnected)
            {
                _labelControllerPresent.Text =  "not present";
                return;
            }

            _labelControllerPresent.Text = "connected";

            var state = _controller.GetState();

            
            _labelHeightValue.Text = _height.ToString();
            _labelRollValue.Text = _roll.ToString();
        }

        private void setupTimer()
        {
            _timer = new DispatcherTimer(DispatcherPriority.Input);
            _timer.Interval = new TimeSpan(0, 0, 0, 0, 100);
            _timer.Tick += timerCallBack;
            _timer.Start();
        }

        private void timerCallBack(object sender, EventArgs e)
        {
            if (_controller == null || !_controller.IsConnected)
            {
                return;
            }

            var state = _controller.GetState().Gamepad;
            _height = (int) ( (32600.0 + state.RightThumbY) / (32600 + 32600.0) * 100.0);
            _roll = (int) ((32600.0 + state.RightThumbX) / (32600 + 32600.0) * 10.0) - 5;

            if (_height != _prevHeight || _roll != _prevRoll)
            {
                UpdateSpider();
                _prevHeight = _height;
                _prevRoll = _roll;
            }

            updateView();
        }

        private void connectController()
        {
            _controller = new Controller(UserIndex.One);
        }

        private void _buttonConnect_Click(object sender, EventArgs e)
        {
            var name = _serialPorts.SelectedItem as String;

            _labelConnectionState.Text = "Connecting...";

            try
            {
                _serialPort.PortName = name;
                _serialPort.BaudRate = (int) _numericBaudRate.Value;
                _serialPort.Open();
                _labelConnectionState.Text = "Connected to " + name;
            }catch(Exception ex)
            {
                _labelConnectionState.Text = "Connection to " + name + " failed " + ex.Message;
            }
        }

        private void fillPortList()
        {
            _serialPorts.Items.Clear();
            _serialPorts.Items.AddRange(serialPortNames);
            if (_serialPorts.Items.Count > 0)
            {
                _serialPorts.SelectedIndex = 0;
            }
        }

        private void _serialPort_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            var line = _serialPort.ReadLine();
            //_labelConnectionState.Text = "RCV=" + line;
            _canSend = true;
            Console.WriteLine(line);
        }

        private void _serialPort_ErrorReceived(object sender, SerialErrorReceivedEventArgs e)
        {
            SerialError err = e.EventType;
            _labelConnectionState.Text = "ERR=" + err.ToString();
        }

        private void _serialPort_PinChanged(object sender, SerialPinChangedEventArgs e)
        {
            _labelConnectionState.Text = "PIN=" + e.EventType.ToString();
        }

        private void _buttonUp_Click(object sender, EventArgs e)
        {
            _height += 5;
            
        }

        private void _buttonDown_Click(object sender, EventArgs e)
        {
            _height -= 5;
            
        }

        private void UpdateSpider()
        {
            if (_serialPort.IsOpen)
            {
                _serialPort.Write(string.Format("height{0}:roll{1}:", _height,_roll));
                _canSend = false;
            }
        }
    }
}
