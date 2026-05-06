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

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        public string getimage(int a)
        {
			string imageselect;
			if (a == 0)
			{
				imageselect = "0.png";
				return imageselect;
			}
			else if (a == 2)
			{
				imageselect = "2.png";
				return imageselect;
			}
			else if (a == 4)
			{
				imageselect = "4.png";
				return imageselect;
			}
			else if (a == 8)
			{
				imageselect = "8.png";
				return imageselect;
			}
			else if (a == 16)
			{
				imageselect = "16.png";
				return imageselect;
			}
			else if (a == 32)
			{
				imageselect = "32.png";
				return imageselect;
			}
			else if (a == 64)
			{
				imageselect = "64.png";
				return imageselect;
			}
			else if (a == 128)
			{
				imageselect = "128.png";
				return imageselect;
			}
			else if (a == 256)
			{
				imageselect = "256.png";
				return imageselect;
			}
			else if (a == 512)
			{
				imageselect = "512.png";
				return imageselect;
			}
			else if (a == 1024)
			{
				imageselect = "1024.png";
				return imageselect;
			}
			else 
			{
				imageselect = "2048.png";
				return imageselect;
			}
		}

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        public void printUI()
		{
			
			pictureBox1.Image = Image.FromFile(getimage(board[0, 0]));
			pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox2.Image = Image.FromFile(getimage(board[0, 1]));
			pictureBox2.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox3.Image = Image.FromFile(getimage(board[0, 2]));
			pictureBox3.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox4.Image = Image.FromFile(getimage(board[0, 3]));
			pictureBox4.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox5.Image = Image.FromFile(getimage(board[1, 0]));
			pictureBox5.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox6.Image = Image.FromFile(getimage(board[1, 1]));
			pictureBox6.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox7.Image = Image.FromFile(getimage(board[1, 2]));
			pictureBox7.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox8.Image = Image.FromFile(getimage(board[1, 3]));
			pictureBox8.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox9.Image = Image.FromFile(getimage(board[2, 0]));
			pictureBox9.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox10.Image = Image.FromFile(getimage(board[2, 1]));
			pictureBox10.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox11.Image = Image.FromFile(getimage(board[2, 2]));
			pictureBox11.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox12.Image = Image.FromFile(getimage(board[2, 3]));
			pictureBox12.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox13.Image = Image.FromFile(getimage(board[3, 0]));
			pictureBox13.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox14.Image = Image.FromFile(getimage(board[3, 1]));
			pictureBox14.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox15.Image = Image.FromFile(getimage(board[3, 2]));
			pictureBox15.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox16.Image = Image.FromFile(getimage(board[3, 3]));
			pictureBox16.SizeMode = PictureBoxSizeMode.StretchImage;
			pictureBox17.Image = Image.FromFile("2048table.png");
			pictureBox17.SizeMode = PictureBoxSizeMode.StretchImage;
			label17.Text = "score: " + "" + point;
			pictureBox1 = null;
			pictureBox2 = null;
			pictureBox3 = null;
			pictureBox4 = null;
			pictureBox5 = null;
			pictureBox6 = null;
			pictureBox7 = null;
			pictureBox8 = null;
			pictureBox9 = null;
			pictureBox10 = null;
			pictureBox11 = null;
			pictureBox12 = null;
			pictureBox13 = null;
			pictureBox14 = null;
			pictureBox15 = null;
			pictureBox16 = null;
		}

		
	}
}
