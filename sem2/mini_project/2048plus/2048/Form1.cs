using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2048
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int mode;
            string name;
            name = textBox1.Text;
            if (radioButton1.Checked == true)
            {
                mode = 1;
                Form2 F2 = new Form2(mode,name);
                F2.ShowDialog();
            }
            if (radioButton2.Checked == true)
            {
                mode = 2;
                Form2 F2 = new Form2(mode,name);
                F2.ShowDialog();
            }
        }
    }
}
