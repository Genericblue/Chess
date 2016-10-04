#pragma once
#include "Board.h"
#include "Rules.h"


namespace ChessApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		///////////////////////////////////////////////
		//where the added things begin
		//displays the board
		void display()
		{
			int x = 0, y = 0, i = 0, empty = 1;
			PictureBox ^ pictureBox;//make a picturebox handle
			//reset all the labels
			label5->Text = "0";
			label6->Text = "0";
			label7->Text = "0";
			label8->Text = "0";
			label9->Text = "0";
			label10->Text = "0";
			label11->Text = "0";
			label12->Text = "0";
			label13->Text = "0";
			label14->Text = "0";
			//display whose turn it is
			if(t%2 == 0)
			{
				textBox1->Text = "Player 1's Turn";
			}
			else
			{
				textBox1->Text = "Player 2's Turn";
			}
			for(x = 0; x < 8; x++)//walk through x
			{
				for(y = 0; y < 8; y++)//walk through y
				{
					pictureBox = getPicture(x,y);//set the picturebox to the one at the right coordiantes
					if(board->getPositions(y,x) == PawnPiece0)// if player 1 pawn
					{
						if(x == 7)//if a pawn is at the end, promote
						{
							textBox1->Text = "Player 1 Replacing";
							replacing = 1;//so later we know to replace the pawn
							rx = x;
							ry = y;
							rt = 0;
						}
						pictureBox->Load("WhitePawn.png");//display pawn
						raiseLabel(label13);//count the number of white pawns
					}
					//repeat
					else if(board->getPositions(y,x) == PawnPiece1)
					{
						if(x == 0)
						{
							textBox1->Text = "Player 2 Replacing";
							replacing = 1;
							rx = x;
							ry = y;
							rt = 1;
						}
						pictureBox->Load("BlackPawn.png");
						raiseLabel(label14);
					}
					//repeat for rook and so on
					else if(board->getPositions(y,x) == RookPiece0)
					{
						pictureBox->Load("WhiteRook.png");
						raiseLabel(label11);
					}
					else if (board->getPositions(y,x) == RookPiece1)
					{
						pictureBox->Load("BlackRook.png");
						raiseLabel(label12);
					}
					else if(board->getPositions(y,x) == KnightPiece0)
					{
						pictureBox->Load("WhiteKnight.png");
						raiseLabel(label9);
					}
					else if(board->getPositions(y,x) == KnightPiece1)
					{
						pictureBox->Load("BlackKnight.png");
						raiseLabel(label10);
					}
					else if(board->getPositions(y,x) == BishopPiece0)
					{
						pictureBox->Load("WhiteBishop.png");
						raiseLabel(label7);
					}
					else if(board->getPositions(y,x) == BishopPiece1)
					{
						pictureBox->Load("BlackBishop.png");
						raiseLabel(label8);
					}
					else if(board->getPositions(y,x) == QueenPiece0)
					{
						pictureBox->Load("WhiteQueen.png");
						raiseLabel(label5);
					}
					else if(board->getPositions(y,x) == QueenPiece1)
					{
						pictureBox->Load("BlackQueen.png");
						raiseLabel(label6);
					}
					else if(board->getPositions(y,x) == KingPiece0)
					{
						pictureBox->Load("WhiteKing.png");
					}
					else if(board->getPositions(y,x) == KingPiece1)
					{
						pictureBox->Load("BlackKing.png");
					}
					else
					{
						if (pictureBox->Image != nullptr) //if there is nothing delete the picture in the picturebox
						{
							delete pictureBox->Image;
							pictureBox->Image = nullptr;
						}
					}
				}
			}
		}
		//finds the right picturebox
		PictureBox ^getPicture(int y, int x)
		{
			if(pictureBox00->MinimumSize.Width == y && pictureBox00->MinimumSize.Height == x)
			{
				return pictureBox00;
			}
			else if(pictureBox01->MinimumSize.Width == y && pictureBox01->MinimumSize.Height == x)
			{
				return pictureBox01;
			}
			else if(pictureBox02->MinimumSize.Width == y && pictureBox02->MinimumSize.Height == x)
			{
				return pictureBox02;
			}
			else if(pictureBox03->MinimumSize.Width == y && pictureBox03->MinimumSize.Height == x)
			{
				return pictureBox03;
			}
			else if(pictureBox04->MinimumSize.Width == y && pictureBox04->MinimumSize.Height == x)
			{
				return pictureBox04;
			}
			else if(pictureBox05->MinimumSize.Width == y && pictureBox05->MinimumSize.Height == x)
			{
				return pictureBox05;
			}
			else if(pictureBox06->MinimumSize.Width == y && pictureBox06->MinimumSize.Height == x)
			{
				return pictureBox06;
			}
			else if(pictureBox07->MinimumSize.Width == y && pictureBox07->MinimumSize.Height == x)
			{
				return pictureBox07;
			}
			else if(pictureBox10->MinimumSize.Width == y && pictureBox10->MinimumSize.Height == x)
			{
				return pictureBox10;
			}
			else if(pictureBox11->MinimumSize.Width == y && pictureBox11->MinimumSize.Height == x)
			{
				return pictureBox11;
			}
			else if(pictureBox12->MinimumSize.Width == y && pictureBox12->MinimumSize.Height == x)
			{
				return pictureBox12;
			}
			else if(pictureBox13->MinimumSize.Width == y && pictureBox13->MinimumSize.Height == x)
			{
				return pictureBox13;
			}
			else if(pictureBox14->MinimumSize.Width == y && pictureBox14->MinimumSize.Height == x)
			{
				return pictureBox14;
			}
			else if(pictureBox15->MinimumSize.Width == y && pictureBox15->MinimumSize.Height == x)
			{
				return pictureBox15;
			}
			else if(pictureBox16->MinimumSize.Width == y && pictureBox16->MinimumSize.Height == x)
			{
				return pictureBox16;
			}
			else if(pictureBox17->MinimumSize.Width == y && pictureBox17->MinimumSize.Height == x)
			{
				return pictureBox17;
			}
			else if(pictureBox20->MinimumSize.Width == y && pictureBox20->MinimumSize.Height == x)
			{
				return pictureBox20;
			}
			else if(pictureBox21->MinimumSize.Width == y && pictureBox21->MinimumSize.Height == x)
			{
				return pictureBox21;
			}
			else if(pictureBox22->MinimumSize.Width == y && pictureBox22->MinimumSize.Height == x)
			{
				return pictureBox22;
			}
			else if(pictureBox23->MinimumSize.Width == y && pictureBox23->MinimumSize.Height == x)
			{
				return pictureBox23;
			}
			else if(pictureBox24->MinimumSize.Width == y && pictureBox24->MinimumSize.Height == x)
			{
				return pictureBox24;
			}
			else if(pictureBox25->MinimumSize.Width == y && pictureBox25->MinimumSize.Height == x)
			{
				return pictureBox25;
			}
			else if(pictureBox26->MinimumSize.Width == y && pictureBox26->MinimumSize.Height == x)
			{
				return pictureBox26;
			}
			else if(pictureBox27->MinimumSize.Width == y && pictureBox27->MinimumSize.Height == x)
			{
				return pictureBox27;
			}
			else if(pictureBox30->MinimumSize.Width == y && pictureBox30->MinimumSize.Height == x)
			{
				return pictureBox30;
			}
			else if(pictureBox31->MinimumSize.Width == y && pictureBox31->MinimumSize.Height == x)
			{
				return pictureBox31;
			}
			else if(pictureBox32->MinimumSize.Width == y && pictureBox32->MinimumSize.Height == x)
			{
				return pictureBox32;
			}
			else if(pictureBox33->MinimumSize.Width == y && pictureBox33->MinimumSize.Height == x)
			{
				return pictureBox33;
			}
			else if(pictureBox34->MinimumSize.Width == y && pictureBox34->MinimumSize.Height == x)
			{
				return pictureBox34;
			}
			else if(pictureBox35->MinimumSize.Width == y && pictureBox35->MinimumSize.Height == x)
			{
				return pictureBox35;
			}
			else if(pictureBox36->MinimumSize.Width == y && pictureBox36->MinimumSize.Height == x)
			{
				return pictureBox36;
			}
			else if(pictureBox37->MinimumSize.Width == y && pictureBox37->MinimumSize.Height == x)
			{
				return pictureBox37;
			}
			else if(pictureBox40->MinimumSize.Width == y && pictureBox40->MinimumSize.Height == x)
			{
				return pictureBox40;
			}
			else if(pictureBox41->MinimumSize.Width == y && pictureBox41->MinimumSize.Height == x)
			{
				return pictureBox41;
			}
			else if(pictureBox42->MinimumSize.Width == y && pictureBox42->MinimumSize.Height == x)
			{
				return pictureBox42;
			}
			else if(pictureBox43->MinimumSize.Width == y && pictureBox43->MinimumSize.Height == x)
			{
				return pictureBox43;
			}
			else if(pictureBox44->MinimumSize.Width == y && pictureBox44->MinimumSize.Height == x)
			{
				return pictureBox44;
			}
			else if(pictureBox45->MinimumSize.Width == y && pictureBox45->MinimumSize.Height == x)
			{
				return pictureBox45;
			}
			else if(pictureBox46->MinimumSize.Width == y && pictureBox46->MinimumSize.Height == x)
			{
				return pictureBox46;
			}
			else if(pictureBox47->MinimumSize.Width == y && pictureBox47->MinimumSize.Height == x)
			{
				return pictureBox47;
			}
			else if(pictureBox50->MinimumSize.Width == y && pictureBox50->MinimumSize.Height == x)
			{
				return pictureBox50;
			}
			else if(pictureBox51->MinimumSize.Width == y && pictureBox51->MinimumSize.Height == x)
			{
				return pictureBox51;
			}
			else if(pictureBox52->MinimumSize.Width == y && pictureBox52->MinimumSize.Height == x)
			{
				return pictureBox52;
			}
			else if(pictureBox53->MinimumSize.Width == y && pictureBox53->MinimumSize.Height == x)
			{
				return pictureBox53;
			}
			else if(pictureBox54->MinimumSize.Width == y && pictureBox54->MinimumSize.Height == x)
			{
				return pictureBox54;
			}
			else if(pictureBox55->MinimumSize.Width == y && pictureBox55->MinimumSize.Height == x)
			{
				return pictureBox55;
			}
			else if(pictureBox56->MinimumSize.Width == y && pictureBox56->MinimumSize.Height == x)
			{
				return pictureBox56;
			}
			else if(pictureBox57->MinimumSize.Width == y && pictureBox57->MinimumSize.Height == x)
			{
				return pictureBox57;
			}
			else if(pictureBox60->MinimumSize.Width == y && pictureBox60->MinimumSize.Height == x)
			{
				return pictureBox60;
			}
			else if(pictureBox61->MinimumSize.Width == y && pictureBox61->MinimumSize.Height == x)
			{
				return pictureBox61;
			}
			else if(pictureBox62->MinimumSize.Width == y && pictureBox62->MinimumSize.Height == x)
			{
				return pictureBox62;
			}
			else if(pictureBox63->MinimumSize.Width == y && pictureBox63->MinimumSize.Height == x)
			{
				return pictureBox63;
			}
			else if(pictureBox64->MinimumSize.Width == y && pictureBox64->MinimumSize.Height == x)
			{
				return pictureBox64;
			}
			else if(pictureBox65->MinimumSize.Width == y && pictureBox65->MinimumSize.Height == x)
			{
				return pictureBox65;
			}
			else if(pictureBox66->MinimumSize.Width == y && pictureBox66->MinimumSize.Height == x)
			{
				return pictureBox66;
			}
			else if(pictureBox67->MinimumSize.Width == y && pictureBox67->MinimumSize.Height == x)
			{
				return pictureBox67;
			}
			else if(pictureBox70->MinimumSize.Width == y && pictureBox70->MinimumSize.Height == x)
			{
				return pictureBox70;
			}
			else if(pictureBox71->MinimumSize.Width == y && pictureBox71->MinimumSize.Height == x)
			{
				return pictureBox71;
			}
			else if(pictureBox72->MinimumSize.Width == y && pictureBox72->MinimumSize.Height == x)
			{
				return pictureBox72;
			}
			else if(pictureBox73->MinimumSize.Width == y && pictureBox73->MinimumSize.Height == x)
			{
				return pictureBox73;
			}
			else if(pictureBox74->MinimumSize.Width == y && pictureBox74->MinimumSize.Height == x)
			{
				return pictureBox74;
			}
			else if(pictureBox75->MinimumSize.Width == y && pictureBox75->MinimumSize.Height == x)
			{
				return pictureBox75;
			}
			else if(pictureBox76->MinimumSize.Width == y && pictureBox76->MinimumSize.Height == x)
			{
				return pictureBox76;
			}
			else //(pictureBox77->MinimumSize.Width == y && pictureBox77->MinimumSize.Height == x)
			{
				return pictureBox77;
			}
		}
		//interprets what the user meant when the clicked a picture box
		void click(int x2, int y2)
		{
			int status = 0;
			PictureBox ^ pictureBox;//make a picturebox handle
			if(replacing != 1)//if a pawn is not being promoted
			{
				textBox2->Text = "";//reset textbox
				if(i%2 == 1)//whether or not this is the first or second click in a cycle, second click moves the piece
				{
					if(board->move(t%2,x,y,x2,y2,status))//if the move was successful
					{
						t++;//increment the team
						display();//display the changes
						win = board->checkmate(t%2);//check for checkmate
					}
					pictureBox = getPicture(x,y);
					pictureBox->BackColor = Color::Transparent;//reset the color
					x = -1;//reset x and y
					y = -1;

					if(win == true)//dispaly for victory
					{
						textBox2->Text = "Checkmate";
						if(t%2 == 0)
						{
							textBox1->Text = "Player 2 Wins";
						}
						else
						{
							textBox1->Text = "Player 1 Wins";
						}
					}

					if(status == 1)//displays for reason you might not be able to move
					{
						textBox2->Text = "No Piece There!";
					}
					else if(status == 2)
					{
						textBox2->Text = "Not Your Piece!";
					}
					else if(status == 3)
					{
						textBox2->Text = "Invalid Move";
					}
					else if(status == 4)
					{
						textBox2->Text = "Your King is in Check";
					}
				}
				else
				{//if it is the first click
					x = x2;//remember the location
					y = y2;
					pictureBox = getPicture(x2,y2);
					pictureBox->BackColor = Color::SteelBlue;//change the color
				}
				i++; //increment the cycle
			}
		}
		//counts the number of each piece
		void raiseLabel(Label^ label)
		{
			if(label->Text == "0")
			{
				label->Text = "1";
			}
			else if(label->Text == "1")
			{
				label->Text = "2";
			}
			else if(label->Text == "2")
			{
				label->Text = "3";
			}
			else if(label->Text == "3")
			{
				label->Text = "4";
			}
			else if(label->Text == "4")
			{
				label->Text = "5";
			}
			else if(label->Text == "5")
			{
				label->Text = "6";
			}
			else if(label->Text == "6")
			{
				label->Text = "7";
			}
			else if(label->Text == "7")
			{
				label->Text = "8";
			}
			else if(label->Text == "8")
			{
				label->Text = "9";
			}
			else if(label->Text == "9")
			{
				label->Text = "10";
			}
		}
		/////////////////////////////////////////////////
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Board *board;
	private: int x;
	private: int y;
	private: int i;
	private: int t;
	private: int replacing;
	private: int rx;
	private: int ry;
	private: int rt;
	private: bool win;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::PictureBox^  pictureBox60;
private: System::Windows::Forms::PictureBox^  pictureBox61;
private: System::Windows::Forms::PictureBox^  pictureBox62;
private: System::Windows::Forms::PictureBox^  pictureBox63;
private: System::Windows::Forms::PictureBox^  pictureBox64;
private: System::Windows::Forms::PictureBox^  pictureBox65;
private: System::Windows::Forms::PictureBox^  pictureBox66;
private: System::Windows::Forms::PictureBox^  pictureBox67;
private: System::Windows::Forms::PictureBox^  pictureBox70;
private: System::Windows::Forms::PictureBox^  pictureBox77;
private: System::Windows::Forms::PictureBox^  pictureBox71;
private: System::Windows::Forms::PictureBox^  pictureBox76;
private: System::Windows::Forms::PictureBox^  pictureBox72;
private: System::Windows::Forms::PictureBox^  pictureBox75;
private: System::Windows::Forms::PictureBox^  pictureBox73;
private: System::Windows::Forms::PictureBox^  pictureBox74;
private: System::Windows::Forms::PictureBox^  pictureBox17;
private: System::Windows::Forms::PictureBox^  pictureBox16;
private: System::Windows::Forms::PictureBox^  pictureBox15;
private: System::Windows::Forms::PictureBox^  pictureBox14;
private: System::Windows::Forms::PictureBox^  pictureBox13;
private: System::Windows::Forms::PictureBox^  pictureBox12;
private: System::Windows::Forms::PictureBox^  pictureBox11;
private: System::Windows::Forms::PictureBox^  pictureBox10;
private: System::Windows::Forms::PictureBox^  pictureBox07;
private: System::Windows::Forms::PictureBox^  pictureBox06;
private: System::Windows::Forms::PictureBox^  pictureBox01;
private: System::Windows::Forms::PictureBox^  pictureBox05;
private: System::Windows::Forms::PictureBox^  pictureBox02;
private: System::Windows::Forms::PictureBox^  pictureBox03;
private: System::Windows::Forms::PictureBox^  pictureBox04;
private: System::Windows::Forms::PictureBox^  pictureBox00;
private: System::Windows::Forms::PictureBox^  pictureBox20;
private: System::Windows::Forms::PictureBox^  pictureBox21;
private: System::Windows::Forms::PictureBox^  pictureBox22;
private: System::Windows::Forms::PictureBox^  pictureBox23;
private: System::Windows::Forms::PictureBox^  pictureBox24;
private: System::Windows::Forms::PictureBox^  pictureBox25;
private: System::Windows::Forms::PictureBox^  pictureBox26;
private: System::Windows::Forms::PictureBox^  pictureBox27;
private: System::Windows::Forms::PictureBox^  pictureBox37;
private: System::Windows::Forms::PictureBox^  pictureBox36;
private: System::Windows::Forms::PictureBox^  pictureBox35;
private: System::Windows::Forms::PictureBox^  pictureBox34;
private: System::Windows::Forms::PictureBox^  pictureBox33;
private: System::Windows::Forms::PictureBox^  pictureBox32;
private: System::Windows::Forms::PictureBox^  pictureBox31;
private: System::Windows::Forms::PictureBox^  pictureBox30;
private: System::Windows::Forms::PictureBox^  pictureBox40;
private: System::Windows::Forms::PictureBox^  pictureBox41;
private: System::Windows::Forms::PictureBox^  pictureBox42;
private: System::Windows::Forms::PictureBox^  pictureBox43;
private: System::Windows::Forms::PictureBox^  pictureBox44;
private: System::Windows::Forms::PictureBox^  pictureBox45;
private: System::Windows::Forms::PictureBox^  pictureBox46;
private: System::Windows::Forms::PictureBox^  pictureBox47;
private: System::Windows::Forms::PictureBox^  pictureBox57;
private: System::Windows::Forms::PictureBox^  pictureBox56;
private: System::Windows::Forms::PictureBox^  pictureBox55;
private: System::Windows::Forms::PictureBox^  pictureBox54;
private: System::Windows::Forms::PictureBox^  pictureBox53;
private: System::Windows::Forms::PictureBox^  pictureBox52;
private: System::Windows::Forms::PictureBox^  pictureBox51;
private: System::Windows::Forms::PictureBox^  pictureBox50;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::PictureBox^  pictureBox3;
private: System::Windows::Forms::PictureBox^  pictureBox4;
private: System::Windows::Forms::PictureBox^  pictureBox5;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label14;





	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox60 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox61 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox62 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox63 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox64 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox65 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox66 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox67 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox70 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox77 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox71 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox76 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox72 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox75 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox73 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox74 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox07 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox06 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox01 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox05 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox02 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox03 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox04 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox00 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox57 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox56 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox55 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox54 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox53 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox52 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox60))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox61))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox62))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox63))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox65))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox66))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox67))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox70))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox77))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox71))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox76))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox72))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox75))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox73))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox74))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox07))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox06))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox01))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox05))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox02))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox03))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox04))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox00))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(678, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 56);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Chess";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(880, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 14);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Mark, Wilson";
			// 
			// pictureBox60
			// 
			this->pictureBox60->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox60->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox60->Location = System::Drawing::Point(33, 433);
			this->pictureBox60->MinimumSize = System::Drawing::Size(6, 0);
			this->pictureBox60->Name = L"pictureBox60";
			this->pictureBox60->Size = System::Drawing::Size(65, 65);
			this->pictureBox60->TabIndex = 3;
			this->pictureBox60->TabStop = false;
			this->pictureBox60->Click += gcnew System::EventHandler(this, &Form1::pictureBox60_Click);
			// 
			// pictureBox61
			// 
			this->pictureBox61->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox61->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox61->Location = System::Drawing::Point(103, 433);
			this->pictureBox61->MinimumSize = System::Drawing::Size(6, 1);
			this->pictureBox61->Name = L"pictureBox61";
			this->pictureBox61->Size = System::Drawing::Size(65, 65);
			this->pictureBox61->TabIndex = 4;
			this->pictureBox61->TabStop = false;
			this->pictureBox61->Click += gcnew System::EventHandler(this, &Form1::pictureBox61_Click);
			// 
			// pictureBox62
			// 
			this->pictureBox62->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox62->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox62->Location = System::Drawing::Point(173, 433);
			this->pictureBox62->MinimumSize = System::Drawing::Size(6, 2);
			this->pictureBox62->Name = L"pictureBox62";
			this->pictureBox62->Size = System::Drawing::Size(65, 65);
			this->pictureBox62->TabIndex = 5;
			this->pictureBox62->TabStop = false;
			this->pictureBox62->Click += gcnew System::EventHandler(this, &Form1::pictureBox62_Click);
			// 
			// pictureBox63
			// 
			this->pictureBox63->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox63->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox63->Location = System::Drawing::Point(243, 433);
			this->pictureBox63->MinimumSize = System::Drawing::Size(6, 3);
			this->pictureBox63->Name = L"pictureBox63";
			this->pictureBox63->Size = System::Drawing::Size(65, 65);
			this->pictureBox63->TabIndex = 6;
			this->pictureBox63->TabStop = false;
			this->pictureBox63->Click += gcnew System::EventHandler(this, &Form1::pictureBox63_Click);
			// 
			// pictureBox64
			// 
			this->pictureBox64->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox64->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox64->Location = System::Drawing::Point(313, 433);
			this->pictureBox64->MinimumSize = System::Drawing::Size(6, 4);
			this->pictureBox64->Name = L"pictureBox64";
			this->pictureBox64->Size = System::Drawing::Size(65, 65);
			this->pictureBox64->TabIndex = 7;
			this->pictureBox64->TabStop = false;
			this->pictureBox64->Click += gcnew System::EventHandler(this, &Form1::pictureBox64_Click);
			// 
			// pictureBox65
			// 
			this->pictureBox65->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox65->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox65->Location = System::Drawing::Point(383, 433);
			this->pictureBox65->MinimumSize = System::Drawing::Size(6, 5);
			this->pictureBox65->Name = L"pictureBox65";
			this->pictureBox65->Size = System::Drawing::Size(65, 65);
			this->pictureBox65->TabIndex = 8;
			this->pictureBox65->TabStop = false;
			this->pictureBox65->Click += gcnew System::EventHandler(this, &Form1::pictureBox65_Click);
			// 
			// pictureBox66
			// 
			this->pictureBox66->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox66->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox66->Location = System::Drawing::Point(453, 433);
			this->pictureBox66->MinimumSize = System::Drawing::Size(6, 6);
			this->pictureBox66->Name = L"pictureBox66";
			this->pictureBox66->Size = System::Drawing::Size(65, 65);
			this->pictureBox66->TabIndex = 9;
			this->pictureBox66->TabStop = false;
			this->pictureBox66->Click += gcnew System::EventHandler(this, &Form1::pictureBox66_Click);
			// 
			// pictureBox67
			// 
			this->pictureBox67->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox67->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox67->Location = System::Drawing::Point(523, 433);
			this->pictureBox67->MinimumSize = System::Drawing::Size(6, 7);
			this->pictureBox67->Name = L"pictureBox67";
			this->pictureBox67->Size = System::Drawing::Size(65, 65);
			this->pictureBox67->TabIndex = 10;
			this->pictureBox67->TabStop = false;
			this->pictureBox67->Click += gcnew System::EventHandler(this, &Form1::pictureBox67_Click);
			// 
			// pictureBox70
			// 
			this->pictureBox70->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox70->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox70->Location = System::Drawing::Point(33, 504);
			this->pictureBox70->MinimumSize = System::Drawing::Size(7, 0);
			this->pictureBox70->Name = L"pictureBox70";
			this->pictureBox70->Size = System::Drawing::Size(65, 65);
			this->pictureBox70->TabIndex = 11;
			this->pictureBox70->TabStop = false;
			this->pictureBox70->Click += gcnew System::EventHandler(this, &Form1::pictureBox70_Click);
			// 
			// pictureBox77
			// 
			this->pictureBox77->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox77->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox77->Location = System::Drawing::Point(523, 504);
			this->pictureBox77->MinimumSize = System::Drawing::Size(7, 7);
			this->pictureBox77->Name = L"pictureBox77";
			this->pictureBox77->Size = System::Drawing::Size(65, 65);
			this->pictureBox77->TabIndex = 12;
			this->pictureBox77->TabStop = false;
			this->pictureBox77->Click += gcnew System::EventHandler(this, &Form1::pictureBox77_Click);
			// 
			// pictureBox71
			// 
			this->pictureBox71->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox71->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox71->Location = System::Drawing::Point(104, 504);
			this->pictureBox71->MinimumSize = System::Drawing::Size(7, 1);
			this->pictureBox71->Name = L"pictureBox71";
			this->pictureBox71->Size = System::Drawing::Size(65, 65);
			this->pictureBox71->TabIndex = 13;
			this->pictureBox71->TabStop = false;
			this->pictureBox71->Click += gcnew System::EventHandler(this, &Form1::pictureBox71_Click);
			// 
			// pictureBox76
			// 
			this->pictureBox76->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox76->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox76->Location = System::Drawing::Point(452, 504);
			this->pictureBox76->MinimumSize = System::Drawing::Size(7, 6);
			this->pictureBox76->Name = L"pictureBox76";
			this->pictureBox76->Size = System::Drawing::Size(65, 65);
			this->pictureBox76->TabIndex = 14;
			this->pictureBox76->TabStop = false;
			this->pictureBox76->Click += gcnew System::EventHandler(this, &Form1::pictureBox76_Click);
			// 
			// pictureBox72
			// 
			this->pictureBox72->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox72->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox72->Location = System::Drawing::Point(172, 504);
			this->pictureBox72->MinimumSize = System::Drawing::Size(7, 2);
			this->pictureBox72->Name = L"pictureBox72";
			this->pictureBox72->Size = System::Drawing::Size(65, 65);
			this->pictureBox72->TabIndex = 15;
			this->pictureBox72->TabStop = false;
			this->pictureBox72->Click += gcnew System::EventHandler(this, &Form1::pictureBox72_Click);
			// 
			// pictureBox75
			// 
			this->pictureBox75->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox75->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox75->Location = System::Drawing::Point(384, 504);
			this->pictureBox75->MinimumSize = System::Drawing::Size(7, 5);
			this->pictureBox75->Name = L"pictureBox75";
			this->pictureBox75->Size = System::Drawing::Size(65, 65);
			this->pictureBox75->TabIndex = 16;
			this->pictureBox75->TabStop = false;
			this->pictureBox75->Click += gcnew System::EventHandler(this, &Form1::pictureBox75_Click);
			// 
			// pictureBox73
			// 
			this->pictureBox73->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox73->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox73->Location = System::Drawing::Point(244, 504);
			this->pictureBox73->MinimumSize = System::Drawing::Size(7, 3);
			this->pictureBox73->Name = L"pictureBox73";
			this->pictureBox73->Size = System::Drawing::Size(65, 65);
			this->pictureBox73->TabIndex = 17;
			this->pictureBox73->TabStop = false;
			this->pictureBox73->Click += gcnew System::EventHandler(this, &Form1::pictureBox73_Click);
			// 
			// pictureBox74
			// 
			this->pictureBox74->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox74->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox74->Location = System::Drawing::Point(315, 504);
			this->pictureBox74->MinimumSize = System::Drawing::Size(7, 4);
			this->pictureBox74->Name = L"pictureBox74";
			this->pictureBox74->Size = System::Drawing::Size(65, 65);
			this->pictureBox74->TabIndex = 18;
			this->pictureBox74->TabStop = false;
			this->pictureBox74->Click += gcnew System::EventHandler(this, &Form1::pictureBox74_Click);
			// 
			// pictureBox17
			// 
			this->pictureBox17->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox17->Location = System::Drawing::Point(523, 83);
			this->pictureBox17->MinimumSize = System::Drawing::Size(1, 7);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(65, 65);
			this->pictureBox17->TabIndex = 19;
			this->pictureBox17->TabStop = false;
			this->pictureBox17->Click += gcnew System::EventHandler(this, &Form1::pictureBox17_Click);
			// 
			// pictureBox16
			// 
			this->pictureBox16->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox16->Location = System::Drawing::Point(453, 83);
			this->pictureBox16->MinimumSize = System::Drawing::Size(1, 6);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(65, 65);
			this->pictureBox16->TabIndex = 20;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->Click += gcnew System::EventHandler(this, &Form1::pictureBox16_Click);
			// 
			// pictureBox15
			// 
			this->pictureBox15->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox15->Location = System::Drawing::Point(382, 83);
			this->pictureBox15->MinimumSize = System::Drawing::Size(1, 5);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(65, 65);
			this->pictureBox15->TabIndex = 21;
			this->pictureBox15->TabStop = false;
			this->pictureBox15->Click += gcnew System::EventHandler(this, &Form1::pictureBox15_Click);
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox14->Location = System::Drawing::Point(313, 83);
			this->pictureBox14->MinimumSize = System::Drawing::Size(1, 4);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(65, 65);
			this->pictureBox14->TabIndex = 22;
			this->pictureBox14->TabStop = false;
			this->pictureBox14->Click += gcnew System::EventHandler(this, &Form1::pictureBox14_Click);
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox13->Location = System::Drawing::Point(244, 83);
			this->pictureBox13->MinimumSize = System::Drawing::Size(1, 3);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(65, 65);
			this->pictureBox13->TabIndex = 23;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Click += gcnew System::EventHandler(this, &Form1::pictureBox13_Click);
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox12->Location = System::Drawing::Point(172, 83);
			this->pictureBox12->MinimumSize = System::Drawing::Size(1, 2);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(65, 65);
			this->pictureBox12->TabIndex = 24;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->Click += gcnew System::EventHandler(this, &Form1::pictureBox12_Click);
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox11->Location = System::Drawing::Point(104, 83);
			this->pictureBox11->MinimumSize = System::Drawing::Size(1, 1);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(65, 65);
			this->pictureBox11->TabIndex = 25;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->Click += gcnew System::EventHandler(this, &Form1::pictureBox11_Click);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox10->Location = System::Drawing::Point(33, 83);
			this->pictureBox10->MinimumSize = System::Drawing::Size(1, 0);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(65, 65);
			this->pictureBox10->TabIndex = 26;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Click += gcnew System::EventHandler(this, &Form1::pictureBox10_Click);
			// 
			// pictureBox07
			// 
			this->pictureBox07->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox07->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox07->Location = System::Drawing::Point(523, 13);
			this->pictureBox07->MinimumSize = System::Drawing::Size(0, 7);
			this->pictureBox07->Name = L"pictureBox07";
			this->pictureBox07->Size = System::Drawing::Size(65, 65);
			this->pictureBox07->TabIndex = 27;
			this->pictureBox07->TabStop = false;
			this->pictureBox07->Click += gcnew System::EventHandler(this, &Form1::pictureBox07_Click);
			// 
			// pictureBox06
			// 
			this->pictureBox06->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox06->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox06->Location = System::Drawing::Point(453, 13);
			this->pictureBox06->MinimumSize = System::Drawing::Size(0, 6);
			this->pictureBox06->Name = L"pictureBox06";
			this->pictureBox06->Size = System::Drawing::Size(65, 65);
			this->pictureBox06->TabIndex = 29;
			this->pictureBox06->TabStop = false;
			this->pictureBox06->Click += gcnew System::EventHandler(this, &Form1::pictureBox06_Click);
			// 
			// pictureBox01
			// 
			this->pictureBox01->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox01->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox01->Location = System::Drawing::Point(103, 13);
			this->pictureBox01->MinimumSize = System::Drawing::Size(0, 1);
			this->pictureBox01->Name = L"pictureBox01";
			this->pictureBox01->Size = System::Drawing::Size(65, 65);
			this->pictureBox01->TabIndex = 30;
			this->pictureBox01->TabStop = false;
			this->pictureBox01->Click += gcnew System::EventHandler(this, &Form1::pictureBox01_Click);
			// 
			// pictureBox05
			// 
			this->pictureBox05->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox05->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox05->Location = System::Drawing::Point(382, 13);
			this->pictureBox05->MinimumSize = System::Drawing::Size(0, 5);
			this->pictureBox05->Name = L"pictureBox05";
			this->pictureBox05->Size = System::Drawing::Size(65, 65);
			this->pictureBox05->TabIndex = 31;
			this->pictureBox05->TabStop = false;
			this->pictureBox05->Click += gcnew System::EventHandler(this, &Form1::pictureBox05_Click);
			// 
			// pictureBox02
			// 
			this->pictureBox02->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox02->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox02->Location = System::Drawing::Point(173, 13);
			this->pictureBox02->MinimumSize = System::Drawing::Size(0, 2);
			this->pictureBox02->Name = L"pictureBox02";
			this->pictureBox02->Size = System::Drawing::Size(65, 65);
			this->pictureBox02->TabIndex = 32;
			this->pictureBox02->TabStop = false;
			this->pictureBox02->Click += gcnew System::EventHandler(this, &Form1::pictureBox02_Click);
			// 
			// pictureBox03
			// 
			this->pictureBox03->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox03->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox03->Location = System::Drawing::Point(243, 13);
			this->pictureBox03->MinimumSize = System::Drawing::Size(0, 3);
			this->pictureBox03->Name = L"pictureBox03";
			this->pictureBox03->Size = System::Drawing::Size(65, 65);
			this->pictureBox03->TabIndex = 33;
			this->pictureBox03->TabStop = false;
			this->pictureBox03->Click += gcnew System::EventHandler(this, &Form1::pictureBox03_Click);
			// 
			// pictureBox04
			// 
			this->pictureBox04->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox04->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox04->Location = System::Drawing::Point(315, 13);
			this->pictureBox04->MinimumSize = System::Drawing::Size(0, 4);
			this->pictureBox04->Name = L"pictureBox04";
			this->pictureBox04->Size = System::Drawing::Size(65, 65);
			this->pictureBox04->TabIndex = 34;
			this->pictureBox04->TabStop = false;
			this->pictureBox04->Click += gcnew System::EventHandler(this, &Form1::pictureBox04_Click);
			// 
			// pictureBox00
			// 
			this->pictureBox00->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox00->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox00->Location = System::Drawing::Point(33, 13);
			this->pictureBox00->Name = L"pictureBox00";
			this->pictureBox00->Size = System::Drawing::Size(65, 65);
			this->pictureBox00->TabIndex = 28;
			this->pictureBox00->TabStop = false;
			this->pictureBox00->Click += gcnew System::EventHandler(this, &Form1::pictureBox00_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(672, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 50);
			this->button1->TabIndex = 35;
			this->button1->Text = L"Start Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox20
			// 
			this->pictureBox20->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox20->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox20->Location = System::Drawing::Point(33, 154);
			this->pictureBox20->MinimumSize = System::Drawing::Size(2, 0);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(65, 65);
			this->pictureBox20->TabIndex = 36;
			this->pictureBox20->TabStop = false;
			this->pictureBox20->Click += gcnew System::EventHandler(this, &Form1::pictureBox20_Click);
			// 
			// pictureBox21
			// 
			this->pictureBox21->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox21->Location = System::Drawing::Point(103, 154);
			this->pictureBox21->MinimumSize = System::Drawing::Size(2, 1);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(65, 65);
			this->pictureBox21->TabIndex = 37;
			this->pictureBox21->TabStop = false;
			this->pictureBox21->Click += gcnew System::EventHandler(this, &Form1::pictureBox21_Click);
			// 
			// pictureBox22
			// 
			this->pictureBox22->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox22->Location = System::Drawing::Point(172, 154);
			this->pictureBox22->MinimumSize = System::Drawing::Size(2, 2);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(65, 65);
			this->pictureBox22->TabIndex = 38;
			this->pictureBox22->TabStop = false;
			this->pictureBox22->Click += gcnew System::EventHandler(this, &Form1::pictureBox22_Click);
			// 
			// pictureBox23
			// 
			this->pictureBox23->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox23->Location = System::Drawing::Point(243, 154);
			this->pictureBox23->MinimumSize = System::Drawing::Size(2, 3);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(65, 65);
			this->pictureBox23->TabIndex = 39;
			this->pictureBox23->TabStop = false;
			this->pictureBox23->Click += gcnew System::EventHandler(this, &Form1::pictureBox23_Click);
			// 
			// pictureBox24
			// 
			this->pictureBox24->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox24->Location = System::Drawing::Point(313, 154);
			this->pictureBox24->MinimumSize = System::Drawing::Size(2, 4);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(65, 65);
			this->pictureBox24->TabIndex = 40;
			this->pictureBox24->TabStop = false;
			this->pictureBox24->Click += gcnew System::EventHandler(this, &Form1::pictureBox24_Click);
			// 
			// pictureBox25
			// 
			this->pictureBox25->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox25->Location = System::Drawing::Point(384, 154);
			this->pictureBox25->MinimumSize = System::Drawing::Size(2, 5);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(65, 65);
			this->pictureBox25->TabIndex = 41;
			this->pictureBox25->TabStop = false;
			this->pictureBox25->Click += gcnew System::EventHandler(this, &Form1::pictureBox25_Click);
			// 
			// pictureBox26
			// 
			this->pictureBox26->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox26->Location = System::Drawing::Point(453, 154);
			this->pictureBox26->MinimumSize = System::Drawing::Size(2, 6);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(65, 65);
			this->pictureBox26->TabIndex = 42;
			this->pictureBox26->TabStop = false;
			this->pictureBox26->Click += gcnew System::EventHandler(this, &Form1::pictureBox26_Click);
			// 
			// pictureBox27
			// 
			this->pictureBox27->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox27->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox27->Location = System::Drawing::Point(523, 154);
			this->pictureBox27->MinimumSize = System::Drawing::Size(2, 7);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(65, 65);
			this->pictureBox27->TabIndex = 43;
			this->pictureBox27->TabStop = false;
			this->pictureBox27->Click += gcnew System::EventHandler(this, &Form1::pictureBox27_Click);
			// 
			// pictureBox37
			// 
			this->pictureBox37->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox37->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox37->Location = System::Drawing::Point(523, 225);
			this->pictureBox37->MinimumSize = System::Drawing::Size(3, 7);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(65, 65);
			this->pictureBox37->TabIndex = 44;
			this->pictureBox37->TabStop = false;
			this->pictureBox37->Click += gcnew System::EventHandler(this, &Form1::pictureBox37_Click);
			// 
			// pictureBox36
			// 
			this->pictureBox36->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox36->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox36->Location = System::Drawing::Point(453, 225);
			this->pictureBox36->MinimumSize = System::Drawing::Size(3, 6);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(65, 65);
			this->pictureBox36->TabIndex = 45;
			this->pictureBox36->TabStop = false;
			this->pictureBox36->Click += gcnew System::EventHandler(this, &Form1::pictureBox36_Click);
			// 
			// pictureBox35
			// 
			this->pictureBox35->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox35->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox35->Location = System::Drawing::Point(384, 225);
			this->pictureBox35->MinimumSize = System::Drawing::Size(3, 5);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(65, 65);
			this->pictureBox35->TabIndex = 46;
			this->pictureBox35->TabStop = false;
			this->pictureBox35->Click += gcnew System::EventHandler(this, &Form1::pictureBox35_Click);
			// 
			// pictureBox34
			// 
			this->pictureBox34->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox34->Location = System::Drawing::Point(313, 225);
			this->pictureBox34->MinimumSize = System::Drawing::Size(3, 4);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(65, 65);
			this->pictureBox34->TabIndex = 47;
			this->pictureBox34->TabStop = false;
			this->pictureBox34->Click += gcnew System::EventHandler(this, &Form1::pictureBox34_Click);
			// 
			// pictureBox33
			// 
			this->pictureBox33->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox33->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox33->Location = System::Drawing::Point(242, 225);
			this->pictureBox33->MinimumSize = System::Drawing::Size(3, 3);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(65, 65);
			this->pictureBox33->TabIndex = 48;
			this->pictureBox33->TabStop = false;
			this->pictureBox33->Click += gcnew System::EventHandler(this, &Form1::pictureBox33_Click);
			// 
			// pictureBox32
			// 
			this->pictureBox32->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox32->Location = System::Drawing::Point(171, 225);
			this->pictureBox32->MinimumSize = System::Drawing::Size(3, 2);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(65, 65);
			this->pictureBox32->TabIndex = 49;
			this->pictureBox32->TabStop = false;
			this->pictureBox32->Click += gcnew System::EventHandler(this, &Form1::pictureBox32_Click);
			// 
			// pictureBox31
			// 
			this->pictureBox31->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox31->Location = System::Drawing::Point(101, 225);
			this->pictureBox31->MinimumSize = System::Drawing::Size(3, 1);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(65, 65);
			this->pictureBox31->TabIndex = 50;
			this->pictureBox31->TabStop = false;
			this->pictureBox31->Click += gcnew System::EventHandler(this, &Form1::pictureBox31_Click);
			// 
			// pictureBox30
			// 
			this->pictureBox30->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox30->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox30->Location = System::Drawing::Point(33, 225);
			this->pictureBox30->MinimumSize = System::Drawing::Size(3, 0);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(65, 65);
			this->pictureBox30->TabIndex = 51;
			this->pictureBox30->TabStop = false;
			this->pictureBox30->Click += gcnew System::EventHandler(this, &Form1::pictureBox30_Click);
			// 
			// pictureBox40
			// 
			this->pictureBox40->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox40->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox40->Location = System::Drawing::Point(33, 296);
			this->pictureBox40->MinimumSize = System::Drawing::Size(4, 0);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(65, 65);
			this->pictureBox40->TabIndex = 52;
			this->pictureBox40->TabStop = false;
			this->pictureBox40->Click += gcnew System::EventHandler(this, &Form1::pictureBox40_Click);
			// 
			// pictureBox41
			// 
			this->pictureBox41->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox41->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox41->Location = System::Drawing::Point(101, 296);
			this->pictureBox41->MinimumSize = System::Drawing::Size(4, 1);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(65, 65);
			this->pictureBox41->TabIndex = 53;
			this->pictureBox41->TabStop = false;
			this->pictureBox41->Click += gcnew System::EventHandler(this, &Form1::pictureBox41_Click);
			// 
			// pictureBox42
			// 
			this->pictureBox42->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox42->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox42->Location = System::Drawing::Point(171, 296);
			this->pictureBox42->MinimumSize = System::Drawing::Size(4, 2);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(65, 65);
			this->pictureBox42->TabIndex = 54;
			this->pictureBox42->TabStop = false;
			this->pictureBox42->Click += gcnew System::EventHandler(this, &Form1::pictureBox42_Click);
			// 
			// pictureBox43
			// 
			this->pictureBox43->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox43->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox43->Location = System::Drawing::Point(243, 296);
			this->pictureBox43->MinimumSize = System::Drawing::Size(4, 3);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(65, 65);
			this->pictureBox43->TabIndex = 55;
			this->pictureBox43->TabStop = false;
			this->pictureBox43->Click += gcnew System::EventHandler(this, &Form1::pictureBox43_Click);
			// 
			// pictureBox44
			// 
			this->pictureBox44->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox44->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox44->Location = System::Drawing::Point(314, 296);
			this->pictureBox44->MinimumSize = System::Drawing::Size(4, 4);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(65, 65);
			this->pictureBox44->TabIndex = 56;
			this->pictureBox44->TabStop = false;
			this->pictureBox44->Click += gcnew System::EventHandler(this, &Form1::pictureBox44_Click);
			// 
			// pictureBox45
			// 
			this->pictureBox45->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox45->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox45->Location = System::Drawing::Point(382, 296);
			this->pictureBox45->MinimumSize = System::Drawing::Size(4, 5);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(65, 65);
			this->pictureBox45->TabIndex = 57;
			this->pictureBox45->TabStop = false;
			this->pictureBox45->Click += gcnew System::EventHandler(this, &Form1::pictureBox45_Click);
			// 
			// pictureBox46
			// 
			this->pictureBox46->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox46->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox46->Location = System::Drawing::Point(453, 296);
			this->pictureBox46->MinimumSize = System::Drawing::Size(4, 6);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(65, 65);
			this->pictureBox46->TabIndex = 58;
			this->pictureBox46->TabStop = false;
			this->pictureBox46->Click += gcnew System::EventHandler(this, &Form1::pictureBox46_Click);
			// 
			// pictureBox47
			// 
			this->pictureBox47->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox47->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox47->Location = System::Drawing::Point(524, 296);
			this->pictureBox47->MinimumSize = System::Drawing::Size(4, 7);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(65, 65);
			this->pictureBox47->TabIndex = 59;
			this->pictureBox47->TabStop = false;
			this->pictureBox47->Click += gcnew System::EventHandler(this, &Form1::pictureBox47_Click);
			// 
			// pictureBox57
			// 
			this->pictureBox57->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox57->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox57->Location = System::Drawing::Point(523, 362);
			this->pictureBox57->MinimumSize = System::Drawing::Size(5, 7);
			this->pictureBox57->Name = L"pictureBox57";
			this->pictureBox57->Size = System::Drawing::Size(65, 65);
			this->pictureBox57->TabIndex = 60;
			this->pictureBox57->TabStop = false;
			this->pictureBox57->Click += gcnew System::EventHandler(this, &Form1::pictureBox57_Click);
			// 
			// pictureBox56
			// 
			this->pictureBox56->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox56->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox56->Location = System::Drawing::Point(452, 362);
			this->pictureBox56->MinimumSize = System::Drawing::Size(5, 6);
			this->pictureBox56->Name = L"pictureBox56";
			this->pictureBox56->Size = System::Drawing::Size(65, 65);
			this->pictureBox56->TabIndex = 61;
			this->pictureBox56->TabStop = false;
			this->pictureBox56->Click += gcnew System::EventHandler(this, &Form1::pictureBox56_Click);
			// 
			// pictureBox55
			// 
			this->pictureBox55->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox55->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox55->Location = System::Drawing::Point(383, 362);
			this->pictureBox55->MinimumSize = System::Drawing::Size(5, 5);
			this->pictureBox55->Name = L"pictureBox55";
			this->pictureBox55->Size = System::Drawing::Size(65, 65);
			this->pictureBox55->TabIndex = 62;
			this->pictureBox55->TabStop = false;
			this->pictureBox55->Click += gcnew System::EventHandler(this, &Form1::pictureBox55_Click);
			// 
			// pictureBox54
			// 
			this->pictureBox54->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox54->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox54->Location = System::Drawing::Point(313, 362);
			this->pictureBox54->MinimumSize = System::Drawing::Size(5, 4);
			this->pictureBox54->Name = L"pictureBox54";
			this->pictureBox54->Size = System::Drawing::Size(65, 65);
			this->pictureBox54->TabIndex = 63;
			this->pictureBox54->TabStop = false;
			this->pictureBox54->Click += gcnew System::EventHandler(this, &Form1::pictureBox54_Click);
			// 
			// pictureBox53
			// 
			this->pictureBox53->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox53->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox53->Location = System::Drawing::Point(244, 362);
			this->pictureBox53->MinimumSize = System::Drawing::Size(5, 3);
			this->pictureBox53->Name = L"pictureBox53";
			this->pictureBox53->Size = System::Drawing::Size(65, 65);
			this->pictureBox53->TabIndex = 64;
			this->pictureBox53->TabStop = false;
			this->pictureBox53->Click += gcnew System::EventHandler(this, &Form1::pictureBox53_Click);
			// 
			// pictureBox52
			// 
			this->pictureBox52->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox52->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox52->Location = System::Drawing::Point(173, 362);
			this->pictureBox52->MinimumSize = System::Drawing::Size(5, 2);
			this->pictureBox52->Name = L"pictureBox52";
			this->pictureBox52->Size = System::Drawing::Size(65, 65);
			this->pictureBox52->TabIndex = 65;
			this->pictureBox52->TabStop = false;
			this->pictureBox52->Click += gcnew System::EventHandler(this, &Form1::pictureBox52_Click);
			// 
			// pictureBox51
			// 
			this->pictureBox51->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox51->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox51->Location = System::Drawing::Point(104, 362);
			this->pictureBox51->MinimumSize = System::Drawing::Size(5, 1);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(65, 65);
			this->pictureBox51->TabIndex = 66;
			this->pictureBox51->TabStop = false;
			this->pictureBox51->Click += gcnew System::EventHandler(this, &Form1::pictureBox51_Click);
			// 
			// pictureBox50
			// 
			this->pictureBox50->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox50->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox50->Location = System::Drawing::Point(33, 362);
			this->pictureBox50->MinimumSize = System::Drawing::Size(5, 0);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(65, 65);
			this->pictureBox50->TabIndex = 67;
			this->pictureBox50->TabStop = false;
			this->pictureBox50->Click += gcnew System::EventHandler(this, &Form1::pictureBox50_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(653, 547);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(229, 20);
			this->textBox1->TabIndex = 68;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(654, 512);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(228, 20);
			this->textBox2->TabIndex = 69;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(725, 154);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(70, 70);
			this->pictureBox1->TabIndex = 70;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(725, 225);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(70, 70);
			this->pictureBox2->TabIndex = 71;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Form1::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(725, 291);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(70, 70);
			this->pictureBox3->TabIndex = 72;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &Form1::pictureBox3_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(725, 357);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(70, 70);
			this->pictureBox4->TabIndex = 73;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &Form1::pictureBox4_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(725, 428);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(70, 70);
			this->pictureBox5->TabIndex = 74;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Form1::pictureBox5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(669, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 75;
			this->label3->Text = L"White";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(827, 154);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 76;
			this->label4->Text = L"Black";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(679, 186);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 77;
			this->label5->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(834, 186);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 78;
			this->label6->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Location = System::Drawing::Point(679, 250);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 79;
			this->label7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Location = System::Drawing::Point(834, 250);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 80;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Location = System::Drawing::Point(679, 317);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 81;
			this->label9->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Location = System::Drawing::Point(834, 317);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 82;
			this->label10->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Location = System::Drawing::Point(679, 381);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 83;
			this->label11->Text = L"0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Location = System::Drawing::Point(834, 381);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(13, 13);
			this->label12->TabIndex = 84;
			this->label12->Text = L"0";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Location = System::Drawing::Point(679, 453);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(13, 13);
			this->label13->TabIndex = 85;
			this->label13->Text = L"0";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Location = System::Drawing::Point(834, 453);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(13, 13);
			this->label14->TabIndex = 86;
			this->label14->Text = L"0";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(960, 600);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox50);
			this->Controls->Add(this->pictureBox51);
			this->Controls->Add(this->pictureBox52);
			this->Controls->Add(this->pictureBox53);
			this->Controls->Add(this->pictureBox54);
			this->Controls->Add(this->pictureBox55);
			this->Controls->Add(this->pictureBox56);
			this->Controls->Add(this->pictureBox57);
			this->Controls->Add(this->pictureBox47);
			this->Controls->Add(this->pictureBox46);
			this->Controls->Add(this->pictureBox45);
			this->Controls->Add(this->pictureBox44);
			this->Controls->Add(this->pictureBox43);
			this->Controls->Add(this->pictureBox42);
			this->Controls->Add(this->pictureBox41);
			this->Controls->Add(this->pictureBox40);
			this->Controls->Add(this->pictureBox30);
			this->Controls->Add(this->pictureBox31);
			this->Controls->Add(this->pictureBox32);
			this->Controls->Add(this->pictureBox33);
			this->Controls->Add(this->pictureBox34);
			this->Controls->Add(this->pictureBox35);
			this->Controls->Add(this->pictureBox36);
			this->Controls->Add(this->pictureBox37);
			this->Controls->Add(this->pictureBox27);
			this->Controls->Add(this->pictureBox26);
			this->Controls->Add(this->pictureBox25);
			this->Controls->Add(this->pictureBox24);
			this->Controls->Add(this->pictureBox23);
			this->Controls->Add(this->pictureBox22);
			this->Controls->Add(this->pictureBox21);
			this->Controls->Add(this->pictureBox20);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox04);
			this->Controls->Add(this->pictureBox03);
			this->Controls->Add(this->pictureBox02);
			this->Controls->Add(this->pictureBox05);
			this->Controls->Add(this->pictureBox01);
			this->Controls->Add(this->pictureBox06);
			this->Controls->Add(this->pictureBox00);
			this->Controls->Add(this->pictureBox07);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->pictureBox14);
			this->Controls->Add(this->pictureBox15);
			this->Controls->Add(this->pictureBox16);
			this->Controls->Add(this->pictureBox17);
			this->Controls->Add(this->pictureBox74);
			this->Controls->Add(this->pictureBox73);
			this->Controls->Add(this->pictureBox75);
			this->Controls->Add(this->pictureBox72);
			this->Controls->Add(this->pictureBox76);
			this->Controls->Add(this->pictureBox71);
			this->Controls->Add(this->pictureBox77);
			this->Controls->Add(this->pictureBox70);
			this->Controls->Add(this->pictureBox67);
			this->Controls->Add(this->pictureBox66);
			this->Controls->Add(this->pictureBox65);
			this->Controls->Add(this->pictureBox64);
			this->Controls->Add(this->pictureBox63);
			this->Controls->Add(this->pictureBox62);
			this->Controls->Add(this->pictureBox61);
			this->Controls->Add(this->pictureBox60);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox60))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox61))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox62))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox63))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox65))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox66))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox67))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox70))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox77))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox71))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox76))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox72))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox75))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox73))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox74))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox07))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox06))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox01))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox05))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox02))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox03))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox04))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox00))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


/////////////////////////////////////////////////////////////////////////////////////
//more added things



#pragma endregion
//start game button
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if(board != nullptr)
		{
			 delete board;//delete the current board
		}
		board = new Board;//make a new one
		t = 0;//change everything important back to its initial state
		replacing = 0;
		win = false;
		display();
		button1->Text = "Restart Game";
}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
//board picturebox functions
private: System::Void pictureBox00_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,0);
		 }
private: System::Void pictureBox01_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,1);
		 }

private: System::Void pictureBox02_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,2);
		 }
private: System::Void pictureBox03_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,3);
		 }
private: System::Void pictureBox04_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,4);
		 }
private: System::Void pictureBox05_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,5);
		 }
private: System::Void pictureBox06_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,6);
		 }
private: System::Void pictureBox07_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(0,7);
		 }
private: System::Void pictureBox10_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,0);
		 }
private: System::Void pictureBox11_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,1);
		 }
private: System::Void pictureBox12_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,2);
		 }
private: System::Void pictureBox13_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,3);
		 }
private: System::Void pictureBox14_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,4);
		 }
private: System::Void pictureBox15_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,5);
		 }
private: System::Void pictureBox16_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,6);
		 }
private: System::Void pictureBox17_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(1,7);
		 }
private: System::Void pictureBox20_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,0);
		 }
private: System::Void pictureBox21_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,1);
		 }
private: System::Void pictureBox22_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,2);
		 }
private: System::Void pictureBox23_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,3);
		 }
private: System::Void pictureBox24_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,4);
		 }
private: System::Void pictureBox25_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,5);
		 }
private: System::Void pictureBox26_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,6);
		 }
private: System::Void pictureBox27_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(2,7);
		 }
private: System::Void pictureBox30_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,0);
		 }
private: System::Void pictureBox31_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,1);
		 }
private: System::Void pictureBox32_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,2);
		 }
private: System::Void pictureBox33_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,3);
		 }
private: System::Void pictureBox34_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,4);
		 }
private: System::Void pictureBox35_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,5);
		 }
private: System::Void pictureBox36_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,6);
		 }
private: System::Void pictureBox37_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(3,7);
		 }
private: System::Void pictureBox40_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,0);
		 }
private: System::Void pictureBox41_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,1);
		 }
private: System::Void pictureBox42_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,2);
		 }
private: System::Void pictureBox43_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,3);
		 }
private: System::Void pictureBox44_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,4);
		 }
private: System::Void pictureBox45_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,5);
		 }
private: System::Void pictureBox46_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,6);
		 }
private: System::Void pictureBox47_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(4,7);
		 }
private: System::Void pictureBox50_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,0);
		 }
private: System::Void pictureBox51_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,1);
		 }
private: System::Void pictureBox52_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,2);
		 }
private: System::Void pictureBox53_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,3);
		 }
private: System::Void pictureBox54_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,4);
		 }
private: System::Void pictureBox55_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,5);
		 }
private: System::Void pictureBox56_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,6);
		 }
private: System::Void pictureBox57_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(5,7);
		 }
private: System::Void pictureBox60_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,0);
		 }
private: System::Void pictureBox61_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,1);
		 }
private: System::Void pictureBox62_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,2);
		 }
private: System::Void pictureBox63_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,3);
		 }
private: System::Void pictureBox64_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,4);
		 }
private: System::Void pictureBox65_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,5);
		 }
private: System::Void pictureBox66_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,6);
		 }
private: System::Void pictureBox67_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(6,7);
		 }
private: System::Void pictureBox70_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,0);
		 }
private: System::Void pictureBox71_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,1);
		 }
private: System::Void pictureBox72_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,2);
		 }
private: System::Void pictureBox73_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,3);
		 }
private: System::Void pictureBox74_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,4);
		 }
private: System::Void pictureBox75_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,5);
		 }
private: System::Void pictureBox76_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,6);
		 }
private: System::Void pictureBox77_Click(System::Object^  sender, System::EventArgs^  e) {
			 click(7,7);
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
//for replacing
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			if(replacing == 1)
			{
				board->replacePawn(1, rx, ry, rt);
			}
			replacing = 0;
			board->update();
			display();
		 }
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
			if(replacing == 1)
			{
				board->replacePawn(2, rx, ry, rt);
			}
			replacing = 0;
			board->update();
			display();
		 }
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(replacing == 1)
			{
				board->replacePawn(3, rx, ry, rt);
			}
			replacing = 0;
			board->update();
			display();
		 }
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
			if(replacing == 1)
			{
				board->replacePawn(4, rx, ry, rt);
			}
			replacing = 0;
			board->update();
			display();
		 }
private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

