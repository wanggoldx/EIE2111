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
using System.IO;

namespace Addressbk2_graphical
{
    public partial class choice4 : Form
    {

        [DllImport("Addressbk2dll.dll")]
        public static extern void remove_record();

        [DllImport("Addressbk2dll.dll")]
        public static extern int search();
        public choice4()
        {
            InitializeComponent();
            label1.Text = "No Match!";
        }

        private void choice4_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string remove_information;
            if (radioButton1.Checked)
            {
                remove_information = textBox1.Text;
                remove_information = remove_information.Replace(" ", "_");
            }
            else if (radioButton2.Checked)
            {
                remove_information = textBox2.Text;
            }
            else
            {
                remove_information = textBox3.Text;
            }

            StreamWriter csharptoc = new StreamWriter("temp.txt");
            csharptoc.WriteLine(remove_information);
            csharptoc.Close();
            int temp = search();
            StreamWriter csharptoc1 = new StreamWriter("temp.txt");
            csharptoc1.WriteLine(remove_information);
            csharptoc1.Close();

            if (temp == 1)
            {
                label1.Text = "Match Found!";
                DialogResult Result;
                Result = MessageBox.Show("Confirm to delete the information?", "Confirm Message", MessageBoxButtons.OKCancel);
                if (Result == DialogResult.OK)
                {
                    remove_record();
                }
                this.Close();
            }
            else if (temp == 2)
            {
                label1.Text = "Match Found!";
                DialogResult Result;
                Result = MessageBox.Show("Confirm to delete the information?", "Confirm Message", MessageBoxButtons.OKCancel);
                if (Result == DialogResult.OK)
                {
                    remove_record();
                }
                this.Close();
            }
            else if (temp == 3)
            {
                label1.Text = "Match Found!";
                DialogResult Result;
                Result = MessageBox.Show("Confirm to delete the information?", "Confirm Message", MessageBoxButtons.OKCancel);
                if (Result == DialogResult.OK)
                {
                    remove_record();
                }
                this.Close();
            }
            else
            {
                label1.Text = "No Match!";
            }    
        }
    }
}
