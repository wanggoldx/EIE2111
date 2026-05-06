using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Media;

namespace _2048
{
    public partial class Form2 : Form
    {
        int[,] board = new int[4, 4];
		int[,] oldboard = new int[4, 4];
		int point, bomb=1;
		int mode;
		string name;
		SoundPlayer soundcombine = new SoundPlayer("2048combine.wav");
		public Form2(int a,string b)
        {
            InitializeComponent();
			mode = a;
			name = b;
			if (a==2)
            {
				label18.Text = "Target score: 350";
				button5.Visible=true;
			}
			else
            {
				label18.Text = "";
				button5.Visible = false;
			}
			newgame();
			printUI();
		}
		public bool generatetwocondition()
        {
			bool checksame=false;
			for (int x = 0; x <= 3; x++)
			{
				for (int y = 0; y <= 3; y++)
				{
					if (board[x, y] != oldboard[x, y])
						checksame=true;
				}
			}
			return checksame;
		}
		public void generatetwo()
		{
			Random rnd = new Random();
			int x = rnd.Next(0,4);
			int y = rnd.Next(0,4);
			while (board[x, y] != 0)
			{
				x = rnd.Next(0, 4);
				y = rnd.Next(0, 4);
			}
			board[x, y] = 2;
		}
		public void newgame()
		{
			point = 0;
			for (int x = 0; x <= 3; x++)
			{
				for (int y = 0; y <= 3; y++)
				{
					board[x,y] = 0;
				}
			}
			generatetwo();
			for (int x = 0; x <= 3; x++)
			{
				for (int y = 0; y <= 3; y++)
				{
					oldboard[x, y] = board[x, y];
				}
			}
		}
		bool gameover()
		{
			bool gameover = true;
			for (int x = 0; x <= 3; x = x + 1)
			{
				for (int y = 0; y <= 3; y = y + 1)
				{
					if (board[x,y] == 0)
						gameover = false;
					if (x > 0 && board[x - 1,y] == board[x,y])
						gameover = false;
					if (y > 0 && board[x,y - 1] == board[x,y])
						gameover = false;
				}
			}
			if (mode == 2 && point > 350)
				gameover = true;
			return gameover;
		}

		private void button2_Click(object sender, EventArgs e)
        {
			bool allspaceeat;
			do
			{
				allspaceeat = true;
				for (int x = 0; x <= 3; x = x + 1)
				{
					for (int y = 1; y <= 3; y = y + 1)
					{
						if ((board[x,y - 1] == 0) && (board[x,y] != 0) && (y != 0))
						{
							board[x,y - 1] = board[x,y - 1] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			for (int x = 0; x <= 3; x = x + 1)
			{
				if ((board[x,0] == -1) && (board[x,1] != 0))
				{
					board[x,0] = 0;
					board[x,1] = 0;
				}
			}
			for (int x = 0; x <= 3; x = x + 1)
			{
				for (int y = 1; y <= 3; y = y + 1)
				{
					if ((board[x,y - 1] == board[x,y]) && board[x, y]!=0)
					{
						board[x,y - 1] = board[x,y - 1] + board[x,y];
						board[x,y] = 0;
						point = point + board[x,y - 1] + board[x,y];
						soundcombine.Play();
					}
				}
			}
			for (int x = 0; x <= 3; x = x + 1)
			{
				for (int y = 1; y <= 3; y = y + 1)
				{
					if ((board[x,y - 1] == 0) && (board[x,y] != 0) && (y != 0))
					{
						board[x,y - 1] = board[x,y - 1] + board[x,y];
						board[x,y] = 0;
					}
				}
			}
			for (int x = 0; x <= 3; x = x + 1)
			{
				for (int y = 1; y <= 3; y = y + 1)
				{
					if ((board[x,y] == -1) && (board[x,y - 1] != 0) && (y != 0))
					{
						board[x,y - 1] = 0;
						board[x,y] = 0;
					}
				}
			}
			do
			{
				allspaceeat = true;
				for (int x = 0; x <= 3; x = x + 1)
				{
					for (int y = 1; y <= 3; y = y + 1)
					{
						if ((board[x,y - 1] == 0) && (board[x,y] != 0) && (y != 0))
						{
							board[x,y - 1] = board[x,y - 1] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			if (generatetwocondition()==true&&gameover()==false)
			{ 
				generatetwo();
				printUI();
			}
			if (gameover() == true)
            {
				this.Close();
				Form3 F3 = new Form3(name,point);
				F3.ShowDialog();
			}
			for (int x = 0; x <= 3; x++)
			{
				for (int y = 0; y <= 3; y++)
				{
					oldboard[x, y] = board[x, y];
				}
			}
		}

        private void button4_Click(object sender, EventArgs e)
        {
			bool allspaceeat;
			do
			{
				allspaceeat = true;
				for (int x = 0; x <= 3; x = x + 1)
				{
					for (int y = 2; y >= 0; y = y - 1)
					{
						if ((board[x,y + 1] == 0) && (board[x,y] != 0))
						{
							board[x,y + 1] = board[x,y + 1] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			for (int x = 0; x <= 3; x = x + 1)
			{
				if ((board[x,3] == -1) && (board[x,2] != 0))
				{
					board[x,3] = 0;
					board[x,2] = 0;
				}
			}
			for (int x = 0; x <= 3; x = x + 1)
			{
				for (int y = 2; y >= 0; y = y - 1)
				{
					if ((board[x,y + 1] == board[x,y]) && board[x, y] != 0)
					{
						board[x,y + 1] = board[x,y + 1] + board[x,y];
						board[x,y] = 0;
						point = point + board[x,y + 1] + board[x,y];
						soundcombine.Play();
					}
				}
			}
			for (int x = 0; x <= 3; x = x + 1)
			{
				for (int y = 2; y >= 0; y = y - 1)
				{
					if ((board[x,y + 1] == 0) && (board[x,y] != 0))
					{
						board[x,y + 1] = board[x,y + 1] + board[x,y];
						board[x,y] = 0;
					}
				}
			}
			for (int x = 0; x <= 3; x = x + 1)
			{
				for (int y = 2; y >= 0; y = y - 1)
				{
					if ((board[x,y] == -1) && (board[x,y + 1] != 0))
					{
						board[x,y + 1] = 0;
						board[x,y] = 0;
					}
				}
			}
			do
			{
				allspaceeat = true;
				for (int x = 0; x <= 3; x = x + 1)
				{
					for (int y = 2; y >= 0; y = y - 1)
					{
						if ((board[x,y + 1] == 0) && (board[x,y] != 0))
						{
							board[x,y + 1] = board[x,y + 1] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			if (generatetwocondition() == true && gameover() == false)
			{
				generatetwo();
				printUI();
			}
			if (gameover() == true)
			{
				this.Close();
				Form3 F3 = new Form3(name, point);
				F3.ShowDialog();
			}
			for (int x = 0; x <= 3; x++)
			{
				for (int y = 0; y <= 3; y++)
				{
					oldboard[x, y] = board[x, y];
				}
			}
		}

        private void button3_Click(object sender, EventArgs e)
        {
			bool allspaceeat;
			do
			{
				allspaceeat = true;
				for (int y = 0; y <= 3; y = y + 1)
				{
					for (int x = 2; x >= 0; x = x - 1)
					{

						if ((board[x + 1,y] == 0) && (board[x,y] != 0) && (x != 3))
						{
							board[x + 1,y] = board[x + 1,y] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			for (int y = 0; y <= 3; y = y + 1)
			{
				if ((board[3,y] == -1) && (board[2,y] != 0))
				{
					board[3,y] = 0;
					board[2,y] = 0;
				}
			}
			for (int y = 0; y <= 3; y = y + 1)
			{
				for (int x = 2; x >= 0; x = x - 1)
				{

					if ((board[x + 1,y] == board[x,y]) && board[x, y] != 0)
					{
						board[x + 1,y] = board[x + 1,y] + board[x,y];
						board[x,y] = 0;
						point = point + board[x + 1,y] + board[x,y];
						soundcombine.Play();
					}
				}
			}
			for (int y = 0; y <= 3; y = y + 1)
			{
				for (int x = 2; x >= 0; x = x - 1)
				{

					if ((board[x + 1,y] == 0) && (board[x,y] != 0) && (x != 3))
					{
						board[x + 1,y] = board[x + 1,y] + board[x,y];
						board[x,y] = 0;
					}
				}
			}
			for (int y = 0; y <= 3; y = y + 1)
			{
				for (int x = 0; x <= 2; x = x + 1)
				{
					if ((board[x,y] == -1) && (board[x + 1,y] != 0) && (x != 3))
					{
						board[x + 1,y] = 0;
						board[x,y] = 0;
					}
				}
			}
			do
			{
				allspaceeat = true;
				for (int y = 0; y <= 3; y = y + 1)
				{
					for (int x = 2; x >= 0; x = x - 1)
					{

						if ((board[x + 1,y] == 0) && (board[x,y] != 0) && (x != 3))
						{
							board[x + 1,y] = board[x + 1,y] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			if (generatetwocondition() == true && gameover() == false)
			{
				generatetwo();
				printUI();
			}
			if (gameover() == true)
			{
				this.Close();
				Form3 F3 = new Form3(name, point);
				F3.ShowDialog();
			}
			for (int x = 0; x <= 3; x++)
			{
				for (int y = 0; y <= 3; y++)
				{
					oldboard[x, y] = board[x, y];
				}
			}
		}

        private void button1_Click(object sender, EventArgs e)
        {
			bool allspaceeat;
			do
			{
				allspaceeat = true;
				for (int y = 0; y <= 3; y = y + 1)
				{
					for (int x = 1; x <= 3; x = x + 1)
					{

						if ((board[x - 1,y] == 0) && (board[x,y] != 0) && (x != 0))
						{
							board[x - 1,y] = board[x - 1,y] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			for (int y = 0; y <= 3; y = y + 1)
			{
				if ((board[0,y] == -1) && (board[1,y] != 0))
				{
					board[0,y] = 0;
					board[1,y] = 0;
				}
			}
			for (int y = 0; y <= 3; y = y + 1)
			{
				for (int x = 1; x <= 3; x = x + 1)
				{

					if ((board[x - 1,y] == board[x,y]) && board[x, y] != 0)
					{
						board[x - 1,y] = board[x - 1,y] + board[x,y];
						board[x,y] = 0;
						point = point + board[x - 1,y] + board[x,y];
						soundcombine.Play();
					}
				}
			}
			for (int y = 0; y <= 3; y = y + 1)
			{
				for (int x = 1; x <= 3; x = x + 1)
				{

					if ((board[x - 1,y] == 0) && (board[x,y] != 0) && (x != 0))
					{
						board[x - 1,y] = board[x - 1,y] + board[x,y];
						board[x,y] = 0;
					}
				}
			}
			for (int y = 0; y <= 3; y = y + 1)
			{
				for (int x = 1; x <= 3; x = x + 1)
				{
					if ((board[x,y] == -1) && (board[x - 1,y] != 0))
					{
						board[x - 1,y] = 0;
						board[x,y] = 0;
					}
				}
			}
			do
			{
				allspaceeat = true;
				for (int y = 0; y <= 3; y = y + 1)
				{
					for (int x = 1; x <= 3; x = x + 1)
					{

						if ((board[x - 1,y] == 0) && (board[x,y] != 0))
						{
							board[x - 1,y] = board[x - 1,y] + board[x,y];
							board[x,y] = 0;
							allspaceeat = false;
						}
					}
				}
			} while (allspaceeat == false);
			if (generatetwocondition() == true && gameover() == false)
			{
				generatetwo();
				printUI();
			}
			if (gameover() == true)
			{
				this.Close();
				Form3 F3 = new Form3(name, point);
				F3.ShowDialog();
			}
			for (int x = 0; x <= 3; x++)
			{
				for (int y = 0; y <= 3; y++)
				{
					oldboard[x, y] = board[x, y];
				}
			}
		}

        private void button5_Click(object sender, EventArgs e)
        {
			if (bomb==1)
			{ 
				Random rnd = new Random();
				int x = rnd.Next(0, 4);
				int y = rnd.Next(0, 4);
				while (board[x, y] != 0)
				{
					x = rnd.Next(0, 4);
					y = rnd.Next(0, 4);
				}
				board[x, y] = -1;
				bomb = 0;
				printUI();
			}
		}

        public void printUI()
		{
			label1.Text = "" + board[0, 0];
			label2.Text = "" + board[0, 1];
			label3.Text = "" + board[0, 2];
			label4.Text = "" + board[0, 3];
			label5.Text = "" + board[1, 0];
			label6.Text = "" + board[1, 1];
			label7.Text = "" + board[1, 2];
			label8.Text = "" + board[1, 3];
			label9.Text = "" + board[2, 0];
			label10.Text = "" + board[2, 1];
			label11.Text = "" + board[2, 2];
			label12.Text = "" + board[2, 3];
			label13.Text = "" + board[3, 0]; 
			label14.Text = "" + board[3, 1];
			label15.Text = "" + board[3, 2];
			label16.Text = "" + board[3, 3];
			label17.Text = "score: " + "" + point;
		}

		
	}
}
