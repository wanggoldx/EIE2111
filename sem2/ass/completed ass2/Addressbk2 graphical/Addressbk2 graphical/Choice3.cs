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
    public partial class Choice3 : Form
    {

        [DllImport("Addressbk2dll.dll")]
        public static extern int search();
        public Choice3()
        {
            InitializeComponent();
            label1.Text = "No Match!";
        }

        private void Choice3_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string search_information;
            if (radioButton1.Checked)
            {
                search_information = textBox1.Text;
                search_information = search_information.Replace(" ", "_");
            }
            else if (radioButton2.Checked)
            {
                search_information = textBox2.Text;
            }
            else
            {
                search_information = textBox3.Text;
            }

            StreamWriter csharptoc = new StreamWriter("temp.txt");
            csharptoc.WriteLine(search_information);
            csharptoc.Close();
            int temp=search();
            
            if (temp == 1)
            {
                label1.Text = "Match Found!";
                StreamReader infofromc = new StreamReader("temp.txt");
                string info = infofromc.ReadLine();
                string[] info2 = info.Split(' ');
                textBox2.Text = info2[0];
                textBox3.Text = info2[1];
                infofromc.Close();
            }
            else if (temp == 2)
            {
                label1.Text = "Match Found!";
                StreamReader infofromc = new StreamReader("temp.txt");
                string info = infofromc.ReadLine();
                string[] info2 = info.Split(' ');
                textBox1.Text = info2[0].Replace("_", " ");
                textBox3.Text = info2[1];
                infofromc.Close();
            }
            else if (temp == 3)
            {
                label1.Text = "Match Found!";
                StreamReader infofromc = new StreamReader("temp.txt");
                string info = infofromc.ReadLine();
                string[] info2 = info.Split(' ');
                textBox1.Text = info2[0].Replace("_", " ");
                textBox2.Text = info2[1];
                infofromc.Close();
            }
            else
            {
                label1.Text = "No Match!";
                if (radioButton1.Checked)
                {
                    textBox2.Text = "";
                    textBox3.Text = "";
                }
                else if (radioButton2.Checked)
                {
                    textBox1.Text = "";
                    textBox3.Text = "";
                }
                else
                {
                    textBox1.Text = "";
                    textBox2.Text = "";
                }
            }
                
        }
    }
}
