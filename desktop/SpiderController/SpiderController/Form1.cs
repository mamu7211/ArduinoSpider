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

namespace SpiderController
{
    public partial class Form1 : Form
    {
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
            _labelConnectionState.Text = "RCV=" + line;
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
    }
}
