using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Runtime.InteropServices;

namespace Addressbk2_graphical
{
    public partial class Form1 : Form
    {

        [DllImport("Addressbk2dll.dll")]
        public static extern void initialization();
        public Form1()
        {
            InitializeComponent();
        }
    
        private void button1_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                initialization();
                string message = "Initialization is completed.";
                string title = "Initialize";
                MessageBox.Show(message, title, MessageBoxButtons.OK);
            }
            if (radioButton2.Checked)
            {
                Form2 F2 = new Form2();
                F2.ShowDialog();
            }
            if (radioButton3.Checked)
            {
                Choice3 F2 = new Choice3();
                F2.ShowDialog();
            }
            if (radioButton4.Checked)
            {
                choice4 F2 = new choice4();
                F2.ShowDialog();
            }
            if (radioButton5.Checked)
            {
                choice5 F3 = new choice5();
                F3.ShowDialog();
            }
            if (radioButton6.Checked)
            {
                this.Close();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
