using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab09
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            imageshow(0);
        }

        int guess = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();
            int answer = rnd.Next(1,3);
           
            if (radioButton1.Checked)
                guess = 1; 

            if (radioButton2.Checked)
                guess = 2;

            if (guess==answer)
            { 
                imageshow(answer);
                MessageBox.Show("Correct", "Result", MessageBoxButtons.OK);
            }
            else
            { 
                imageshow(answer);
                MessageBox.Show("Wrong", "Result", MessageBoxButtons.OK);
            }
        }

        void imageshow(int a)
        {
            if (guess == 0)
            {
                pictureBox1.Visible = true;
                pictureBox1.Image = Image.FromFile("images\\back.jpg");
            }
            if (a == 1)
            {
                pictureBox1.Visible = true;
                pictureBox1.Image = Image.FromFile("images\\s1.jpg");
            }
            if (a == 2)
            {
                pictureBox1.Visible = true;
                pictureBox1.Image = Image.FromFile("images\\h1.jpg");
            }
        }
    }
}
