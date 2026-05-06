using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Addressbk2_graphical
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string number_of_record_create= textBox1.Text;
            if (number_of_record_create != "1" && number_of_record_create != "2" && number_of_record_create != "3" && number_of_record_create != "4" && number_of_record_create != "5" && number_of_record_create != "6" && number_of_record_create != "7" && number_of_record_create != "8" && number_of_record_create != "9" && number_of_record_create != "10")
            {
                MessageBox.Show("The input is invalid.It must be an integer not greater than 10.", "Warning!",MessageBoxButtons.OK);
            }
            else
            {
                this.Close();
                create_record_enter_info create_record_enter_info = new create_record_enter_info(Int32.Parse(number_of_record_create));
                create_record_enter_info.ShowDialog();
            }
        }
    }
}
