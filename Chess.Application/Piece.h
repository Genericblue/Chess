#ifndef PIECE_H
#define PIECE_H

enum pieceType
{
	//Negatives for team 0/Player 1
	PawnPiece0=-6,
	KingPiece0=-5,
	QueenPiece0=-4,
	BishopPiece0=-3,
	KnightPiece0=-2,
	RookPiece0=-1,
	NoPiece=0,
	RookPiece1=1,
	KnightPiece1=2,
	BishopPiece1=3,
	QueenPiece1=4,
	KingPiece1=5,
	PawnPiece1=6
	//Positives for team 1/Player 2
};

class Piece
{
	public:
		//constructor
		Piece()
		{

		}
		//destructor
		~Piece()
		{

		}
		//returns xPosition
		int getX()
		{
			return xPosition;
		}
		//returns yPosition
		int getY()
		{
			return yPosition;
		}
		//returns team
		int getTeam()
		{
			return team;
		}
		//returns type
		pieceType getType()
		{
			return type;
		}
		//alive setter
		void setAlive(bool newAlive)
		{
			alive = newAlive;
		}
		//x setter
		void setX(int newX)
		{
			xPosition = newX;
		}
		//y setter
		void setY(int newY)
		{
			yPosition = newY;
		}
		//returns alive
		bool getAlive()
		{
			return alive;
		}
		//returns false if there is a piece inbetween this piece and the sepcified coordinate
		bool inBetween(pieceType positions[8][8], int x, int y)
		{
			int i = 0;
			bool success = true;
			if(x == xPosition)//if it is along the y axis
			{
				if(y > yPosition)//to the right
				{
					for(i = 1; i <= y - yPosition - 1; i++) // check every spot in between
					{
						if(positions[yPosition + i][xPosition] != NoPiece)
						{
							success = false;
						}
					}
				}
				else if(y < yPosition)//to the left
				{
					for(i = 1; i <= yPosition - y - 1; i++)
					{
						if(positions[yPosition - i][xPosition] != NoPiece)
						{
							success = false;
						}
					}
				}
			}
			else if(y == yPosition)//if it is along the x axis
			{
				if(x > xPosition)//down
				{
					for(i = 1; i <= x - xPosition - 1; i++)
					{
						if(positions[yPosition][xPosition + i] != NoPiece)
						{
							success = false;
						}
					}
				}
				else if(x < xPosition)//up
				{
					for(i = 1; i <= xPosition - x - 1; i++)
					{
						if(positions[yPosition][xPosition - i] != NoPiece)
						{
							success = false;
						}
					}
				}
			}
			else//diagonal
			{
				if(x > xPosition && y > yPosition)//down right
				{
					for(i = 1; i <= x - xPosition - 1; i++)
					{
						if(positions[yPosition + i][xPosition + i] != NoPiece)
						{
							success = false;
						}
					}
				}
				else if(x > xPosition && y < yPosition)//down left
				{
					for(i = 1; i <= x - xPosition - 1; i++)
					{
						if(positions[yPosition - i][xPosition + i] != NoPiece)
						{
							success = false;
						}
					}
				}
				else if(x < xPosition && y > yPosition)//up left
				{
					for(i = 1; i <= xPosition - x - 1; i++)
					{
						if(positions[yPosition + i][xPosition - i] != NoPiece)
						{
							success = false;
						}
					}
				}
				else if(x < xPosition && y < yPosition)//down right
				{
					for(i = 1; i <= xPosition - x - 1; i++)
					{
						if(positions[yPosition - i][xPosition - i] != NoPiece)
						{
							success = false;
						}
					}
				}
			}
			return success;
		}
		//pure virtual function for the movement of pieces
		virtual bool move(pieceType positions[8][8], int x, int y, bool &death, bool check) = 0;
		//virutal setter for start
		virtual void setStart(bool newStart)
		{
		}
		//virutal getter for start
		virtual bool getStart()
		{
			return false;
		}
		//virtual function to see if piece has a start variable
		virtual bool hasStart()
		{
			return false;
		}
		//virtual getter for castling
		virtual int isCastling()
		{
			return 0;
		}
		//virtual getter for moved
		virtual bool getMoved()
		{
			return false;
		}
		//virtual setter for moved
		virtual void setMoved(bool newMoved)
		{

		}
	protected:
		pieceType type;//what type of piece the piece is, see enum pieceType
		bool alive;//whether or not the piece is alive (true for yes, false for no)
		int team;//the player who the piece belongs to
		int xPosition;//position along the x axis
		int yPosition;//position along the y axis
};

#endif