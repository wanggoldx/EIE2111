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
    public partial class create_record_enter_info : Form
    {
		[DllImport("Addressbk2dll.dll")]
		public static extern void create_new_record();

		String[] name = new String[11];
		String[] email = new String[11];
		String[] phonenum = new String[11];
		int number_of_record_create;
		int current_record=1;

        public create_record_enter_info(int a)
        {
            InitializeComponent();
            number_of_record_create = a;
			label5.Text = "(Record "+ current_record +" of "+number_of_record_create + ")";
		}

		public bool check_valid(string a, string b, string c)
        {
			bool judge = true;
			bool actexist = false;

			for (int i = 0; i <= (a.Length - 1); i = i + 1)
			{
				if ((a[i] != ' ') && (!Char.IsLetter(a[i])))
				{
					judge = false;
				}
			};

			for (int i = 0; i <= (b.Length - 1); i = i + 1)
			{
				if (b[i] == '@')
					actexist = true;
				if ((b[0] == '@') || (b[b.Length - 1] == '@'))
				{
					judge = false;
				}
			}
			if (actexist == false)
			{
				judge = false;
			}

			for (int i = 0; i <= (c.Length - 1); i = i + 1)
			{
				if ((c.Length != 8) || (!Char.IsDigit(c[i])))
				{
					judge = false;
				}
			};

			return judge;
		}

        private void label1_Click(object sender, EventArgs e)
        {
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
			name[current_record] = textBox1.Text;
			email[current_record] = textBox2.Text;
			phonenum[current_record] = textBox3.Text;
			bool valid_of_record,all_record_valid=true;
			for (int i = 1; i <= number_of_record_create; i = i + 1)
			{
				valid_of_record = check_valid(name[i], email[i], phonenum[i]);
				if (valid_of_record == false)
				{
					all_record_valid = false;
				}
			}

			if (all_record_valid==true)
			{ 
				for (int i = 1; i <= number_of_record_create; i = i + 1)
				{
					StreamWriter csharptoc = new StreamWriter("temp.txt");
					string change = name[i];
					change = change.Replace(" ", "_");
					csharptoc.WriteLine(change + " " + email[i] + " " + phonenum[i]);
					csharptoc.Close();
					create_new_record();
				}
				this.Close();
			}
			else
			{
				MessageBox.Show("Invalid input! Please check again", "Warning", MessageBoxButtons.OK);
			}
		}
        private void button2_Click(object sender, EventArgs e)
        {
			if (number_of_record_create != 1)
			{
				if (current_record < number_of_record_create)
				{
					name[current_record] = textBox1.Text;
					email[current_record] = textBox2.Text;
					phonenum[current_record] = textBox3.Text;

					current_record = current_record + 1;
					label5.Text = "(Record " + current_record + " of " + number_of_record_create + ")";

					textBox1.Text = name[current_record];
					textBox2.Text = email[current_record];
					textBox3.Text = phonenum[current_record];
				}
			}
			else
			{
				label5.Text = "(Record " + current_record + " of " + number_of_record_create + ")";
			}
		}

        private void button1_Click(object sender, EventArgs e)
        {
			if (number_of_record_create != 1)
			{
				if (current_record >1)
				{
					name[current_record] = textBox1.Text;
					email[current_record] = textBox2.Text;
					phonenum[current_record] = textBox3.Text;

					current_record = current_record - 1;
					label5.Text = "(Record " + current_record + " of " + number_of_record_create + ")";

					textBox1.Text = name[current_record];
					textBox2.Text = email[current_record];
					textBox3.Text = phonenum[current_record];
				}
			}
            else
            {
				label5.Text = "(Record " + current_record + " of " + number_of_record_create + ")";
			}
		}

        private void label5_Click(object sender, EventArgs e)
        {
        }

        private void create_record_enter_info_Load(object sender, EventArgs e)
        {

        }
    }
}
