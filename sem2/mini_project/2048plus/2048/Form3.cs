using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO;

namespace _2048
{
    public partial class Form3 : Form
    {
        int point;
        string name;
        string[] best5name = new string[5];
        string[] best5score = new string[5];
       
        public Form3(string a, int b)
        {
            for (int y = 0; y <= 4; y = y + 1)
            {
                best5name[y] = "";
                best5score[y] = "";
            }
            string line;
            InitializeComponent();
            name = a;
            point = b;
            StreamReader sr = new StreamReader("ranking.txt");
            line = sr.ReadLine();
            string[] lines;
            int numberofrecord = -1;
            while (line != null)
            {
                numberofrecord = numberofrecord + 1;
                lines = line.Split(' ');
                best5name[numberofrecord] = lines[0];
                best5score[numberofrecord] = lines[1];
                line = sr.ReadLine();
            }
            sr.Close();
            MessageBox.Show("" + numberofrecord, "有回傳值顯示");
            bool check = false;
            int temp=0;
            if (numberofrecord==-1)
            {
                label2.Text = name;
                label3.Text = "" + point;
                label4.Text = best5name[1];
                label5.Text = best5score[1];
                label6.Text = best5name[2];
                label7.Text = best5score[2];
                label8.Text = best5name[3];
                label9.Text = best5score[3];
                label10.Text = best5name[4];
                label11.Text = best5score[4];
                StreamWriter sw = new StreamWriter("ranking.txt");
                sw.WriteLine(name + " " + point);
                sw.Close();
            }
            else if (numberofrecord <4)
            {
                do
                {
                    if (point > Int32.Parse(best5score[temp]))
                    {
                        int tempposition = 4;
                        while (tempposition != temp)
                        {
                            best5name[tempposition] = best5name[tempposition - 1];
                            best5score[tempposition] = best5score[tempposition - 1];
                            tempposition = tempposition - 1;
                        }
                        MessageBox.Show("" + temp, "有回傳值顯示");
                        best5name[temp] = name;
                        best5score[temp] = "" + point;
                        check = true;
                    }
                    else
                    {
                        temp = temp + 1;
                    }
                } while (temp != numberofrecord && check != true);
                if (best5score[temp] == "")
                {
                    best5name[temp] = name;
                    best5score[temp] = "" + point;
                }
                label2.Text = best5name[0];
                label3.Text = best5score[0];
                label4.Text = best5name[1];
                label5.Text = best5score[1];
                label6.Text = best5name[2];
                label7.Text = best5score[2];
                label8.Text = best5name[3];
                label9.Text = best5score[3];
                label10.Text = best5name[4];
                label11.Text = best5score[4];
                StreamWriter sw = new StreamWriter("ranking.txt");
                for (int u = 0; u <= numberofrecord; u = u + 1)
                    sw.WriteLine(best5name[u] + " " + best5score[u]);
                sw.Close();
            }
            else
            {
                while (temp - 1 != numberofrecord && check != true)
                {
                    if (point > Int32.Parse(best5score[temp]))
                    {
                        int tempposition = 4;
                        while (tempposition != temp)
                        {
                            best5name[tempposition] = best5name[tempposition - 1];
                            best5score[tempposition] = best5score[tempposition - 1];
                            tempposition = tempposition - 1;
                        }
                        best5name[temp] = name;
                        best5score[temp] = "" + point;
                        check = true;
                    }
                    else
                    {
                        temp = temp + 1;
                    }
                }
                label2.Text = best5name[0];
                label3.Text = best5score[0];
                label4.Text = best5name[1];
                label5.Text = best5score[1];
                label6.Text = best5name[2];
                label7.Text = best5score[2];
                label8.Text = best5name[3];
                label9.Text = best5score[3];
                label10.Text = best5name[4];
                label11.Text = best5score[4];
                StreamWriter sw = new StreamWriter("ranking.txt");
                for (int u = 0; u <= numberofrecord; u = u + 1)
                    sw.WriteLine(best5name[u] + " " + best5score[u]);
                sw.Close();
            }

        }

    }
}
