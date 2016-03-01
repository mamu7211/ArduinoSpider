namespace SpiderController
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this._buttonConnect = new System.Windows.Forms.Button();
            this._labelSerialPort = new System.Windows.Forms.Label();
            this._serialPort = new System.IO.Ports.SerialPort(this.components);
            this._labelBaudRate = new System.Windows.Forms.Label();
            this._buttonRefresh = new System.Windows.Forms.Button();
            this._serialPorts = new System.Windows.Forms.ComboBox();
            this._labelConnectionState = new System.Windows.Forms.Label();
            this._numericBaudRate = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this._labelControllerPresent = new System.Windows.Forms.Label();
            this._labelHeight = new System.Windows.Forms.Label();
            this._labelHeightValue = new System.Windows.Forms.Label();
            this._buttonUp = new System.Windows.Forms.Button();
            this._buttonDown = new System.Windows.Forms.Button();
            this._labelRoll = new System.Windows.Forms.Label();
            this._labelRollValue = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this._numericBaudRate)).BeginInit();
            this.SuspendLayout();
            // 
            // _buttonConnect
            // 
            this._buttonConnect.Location = new System.Drawing.Point(202, 31);
            this._buttonConnect.Name = "_buttonConnect";
            this._buttonConnect.Size = new System.Drawing.Size(75, 23);
            this._buttonConnect.TabIndex = 0;
            this._buttonConnect.Text = "Connect";
            this._buttonConnect.UseVisualStyleBackColor = true;
            this._buttonConnect.Click += new System.EventHandler(this._buttonConnect_Click);
            // 
            // _labelSerialPort
            // 
            this._labelSerialPort.AutoSize = true;
            this._labelSerialPort.Location = new System.Drawing.Point(12, 9);
            this._labelSerialPort.Name = "_labelSerialPort";
            this._labelSerialPort.Size = new System.Drawing.Size(55, 13);
            this._labelSerialPort.TabIndex = 1;
            this._labelSerialPort.Text = "Serial Port";
            // 
            // _serialPort
            // 
            this._serialPort.ErrorReceived += new System.IO.Ports.SerialErrorReceivedEventHandler(this._serialPort_ErrorReceived);
            this._serialPort.PinChanged += new System.IO.Ports.SerialPinChangedEventHandler(this._serialPort_PinChanged);
            this._serialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this._serialPort_DataReceived);
            // 
            // _labelBaudRate
            // 
            this._labelBaudRate.AutoSize = true;
            this._labelBaudRate.Cursor = System.Windows.Forms.Cursors.Arrow;
            this._labelBaudRate.Location = new System.Drawing.Point(12, 35);
            this._labelBaudRate.Name = "_labelBaudRate";
            this._labelBaudRate.Size = new System.Drawing.Size(58, 13);
            this._labelBaudRate.TabIndex = 3;
            this._labelBaudRate.Text = "Baud Rate";
            // 
            // _buttonRefresh
            // 
            this._buttonRefresh.Location = new System.Drawing.Point(289, 4);
            this._buttonRefresh.Name = "_buttonRefresh";
            this._buttonRefresh.Size = new System.Drawing.Size(75, 23);
            this._buttonRefresh.TabIndex = 5;
            this._buttonRefresh.Text = "Refresh Serial Ports";
            this._buttonRefresh.UseVisualStyleBackColor = true;
            // 
            // _serialPorts
            // 
            this._serialPorts.FormattingEnabled = true;
            this._serialPorts.Location = new System.Drawing.Point(73, 4);
            this._serialPorts.Name = "_serialPorts";
            this._serialPorts.Size = new System.Drawing.Size(210, 21);
            this._serialPorts.TabIndex = 6;
            // 
            // _labelConnectionState
            // 
            this._labelConnectionState.AutoSize = true;
            this._labelConnectionState.Cursor = System.Windows.Forms.Cursors.Arrow;
            this._labelConnectionState.ForeColor = System.Drawing.SystemColors.ControlText;
            this._labelConnectionState.Location = new System.Drawing.Point(154, 63);
            this._labelConnectionState.Name = "_labelConnectionState";
            this._labelConnectionState.Size = new System.Drawing.Size(0, 13);
            this._labelConnectionState.TabIndex = 7;
            // 
            // _numericBaudRate
            // 
            this._numericBaudRate.Increment = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this._numericBaudRate.Location = new System.Drawing.Point(76, 33);
            this._numericBaudRate.Maximum = new decimal(new int[] {
            999999,
            0,
            0,
            0});
            this._numericBaudRate.Name = "_numericBaudRate";
            this._numericBaudRate.Size = new System.Drawing.Size(120, 20);
            this._numericBaudRate.TabIndex = 6;
            this._numericBaudRate.Value = new decimal(new int[] {
            9600,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 63);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(51, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Controller";
            // 
            // _labelControllerPresent
            // 
            this._labelControllerPresent.AutoSize = true;
            this._labelControllerPresent.Location = new System.Drawing.Point(76, 63);
            this._labelControllerPresent.Name = "_labelControllerPresent";
            this._labelControllerPresent.Size = new System.Drawing.Size(51, 13);
            this._labelControllerPresent.TabIndex = 9;
            this._labelControllerPresent.Text = "Controller";
            // 
            // _labelHeight
            // 
            this._labelHeight.AutoSize = true;
            this._labelHeight.Location = new System.Drawing.Point(32, 87);
            this._labelHeight.Name = "_labelHeight";
            this._labelHeight.Size = new System.Drawing.Size(38, 13);
            this._labelHeight.TabIndex = 10;
            this._labelHeight.Text = "Height";
            // 
            // _labelHeightValue
            // 
            this._labelHeightValue.AutoSize = true;
            this._labelHeightValue.Location = new System.Drawing.Point(76, 87);
            this._labelHeightValue.Name = "_labelHeightValue";
            this._labelHeightValue.Size = new System.Drawing.Size(13, 13);
            this._labelHeightValue.TabIndex = 11;
            this._labelHeightValue.Text = "0";
            // 
            // _buttonUp
            // 
            this._buttonUp.Location = new System.Drawing.Point(214, 226);
            this._buttonUp.Name = "_buttonUp";
            this._buttonUp.Size = new System.Drawing.Size(75, 23);
            this._buttonUp.TabIndex = 12;
            this._buttonUp.Text = "up";
            this._buttonUp.UseVisualStyleBackColor = true;
            this._buttonUp.Click += new System.EventHandler(this._buttonUp_Click);
            // 
            // _buttonDown
            // 
            this._buttonDown.Location = new System.Drawing.Point(214, 255);
            this._buttonDown.Name = "_buttonDown";
            this._buttonDown.Size = new System.Drawing.Size(75, 23);
            this._buttonDown.TabIndex = 13;
            this._buttonDown.Text = "down";
            this._buttonDown.UseVisualStyleBackColor = true;
            this._buttonDown.Click += new System.EventHandler(this._buttonDown_Click);
            // 
            // _labelRoll
            // 
            this._labelRoll.AutoSize = true;
            this._labelRoll.Location = new System.Drawing.Point(42, 110);
            this._labelRoll.Name = "_labelRoll";
            this._labelRoll.Size = new System.Drawing.Size(25, 13);
            this._labelRoll.TabIndex = 14;
            this._labelRoll.Text = "Roll";
            // 
            // _labelRollValue
            // 
            this._labelRollValue.AutoSize = true;
            this._labelRollValue.Location = new System.Drawing.Point(76, 110);
            this._labelRollValue.Name = "_labelRollValue";
            this._labelRollValue.Size = new System.Drawing.Size(13, 13);
            this._labelRollValue.TabIndex = 15;
            this._labelRollValue.Text = "0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(825, 588);
            this.Controls.Add(this._labelRollValue);
            this.Controls.Add(this._labelRoll);
            this.Controls.Add(this._buttonDown);
            this.Controls.Add(this._buttonUp);
            this.Controls.Add(this._labelHeightValue);
            this.Controls.Add(this._labelHeight);
            this.Controls.Add(this._labelControllerPresent);
            this.Controls.Add(this.label1);
            this.Controls.Add(this._numericBaudRate);
            this.Controls.Add(this._labelConnectionState);
            this.Controls.Add(this._serialPorts);
            this.Controls.Add(this._buttonRefresh);
            this.Controls.Add(this._labelBaudRate);
            this.Controls.Add(this._labelSerialPort);
            this.Controls.Add(this._buttonConnect);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this._numericBaudRate)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button _buttonConnect;
        private System.Windows.Forms.Label _labelSerialPort;
        private System.IO.Ports.SerialPort _serialPort;
        private System.Windows.Forms.Label _labelBaudRate;
        private System.Windows.Forms.Button _buttonRefresh;
        private System.Windows.Forms.ComboBox _serialPorts;
        private System.Windows.Forms.Label _labelConnectionState;
        private System.Windows.Forms.NumericUpDown _numericBaudRate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label _labelControllerPresent;
        private System.Windows.Forms.Label _labelHeight;
        private System.Windows.Forms.Label _labelHeightValue;
        private System.Windows.Forms.Button _buttonUp;
        private System.Windows.Forms.Button _buttonDown;
        private System.Windows.Forms.Label _labelRoll;
        private System.Windows.Forms.Label _labelRollValue;
    }
}

