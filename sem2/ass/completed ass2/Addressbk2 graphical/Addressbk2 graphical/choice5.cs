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
    public partial class choice5 : Form
    {
        [DllImport("Addressbk2dll.dll")]
        public static extern void print_out_name(int a);
        [DllImport("Addressbk2dll.dll")]
        public static extern void print_out_email(int a);
        [DllImport("Addressbk2dll.dll")]
        public static extern int print_out_phonenumber(int a);
        [DllImport("Addressbk2dll.dll")]
        public static extern int record_total_number();

        int current_record = 0;
        int total_record = record_total_number();
        string tempcsharp = "";
        public choice5()
        {
            InitializeComponent();
            current_record = 1;
            print_out_name(current_record);
            StreamReader name = new StreamReader("temp.txt");
            tempcsharp = name.ReadLine();
            textBox1.Text = tempcsharp;
            name.Close();
            print_out_email(current_record);
            StreamReader email = new StreamReader("temp.txt");
            tempcsharp = email.ReadLine();
            textBox2.Text = tempcsharp;
            email.Close();
            textBox3.Text = "" + print_out_phonenumber(current_record);
            label4.Text = "(Record " + current_record + " of " + total_record + ")";
        }



        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (current_record < total_record)
            {
                current_record = current_record + 1;
                print_out_name(current_record);
                StreamReader name = new StreamReader("temp.txt");
                tempcsharp = name.ReadLine();
                textBox1.Text = tempcsharp;
                name.Close();
                print_out_email(current_record);
                StreamReader email = new StreamReader("temp.txt");
                tempcsharp = email.ReadLine();
                textBox2.Text = tempcsharp;
                email.Close();
                textBox3.Text = "" + print_out_phonenumber(current_record);
                label4.Text = "(Record " + current_record + " of " + total_record + ")";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (1 < current_record) 
            {
                current_record = current_record - 1;
                print_out_name(current_record);
                StreamReader name = new StreamReader("temp.txt");
                tempcsharp = name.ReadLine();
                textBox1.Text = tempcsharp;
                name.Close();
                print_out_email(current_record);
                StreamReader email = new StreamReader("temp.txt");
                tempcsharp = email.ReadLine();
                textBox2.Text = tempcsharp;
                email.Close();
                textBox3.Text = "" + print_out_phonenumber(current_record);
                label4.Text = "(Record " + current_record + " of " + total_record + ")";
            }
        }
    }
}
