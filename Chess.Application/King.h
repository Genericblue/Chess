#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
	public:
		//constructor
		King(int newTeam, int x, int y)
		{
			alive = true;
			start = true;
			castling = 0;
			team = newTeam;
			xPosition = x;
			yPosition = y;
			if(team == 0)
			{
				type = KingPiece0;
			}
			else
			{
				type = KingPiece1;
			}	
		}
		//destructor
		~King()
		{

		}
		//move function
		bool move(pieceType positions[8][8], int x, int y, bool &death, bool check)
		{
			bool success = false;
			castling = 0;
			if((x == xPosition + 1 || x == xPosition - 1 || x == xPosition) &&
				(y == yPosition + 1 || y == yPosition - 1 || y == yPosition))//only moving one space
			{
				if(team == 0)//player 1
				{
					if(positions[y][x] >= NoPiece)
					{
						if(!check)
						{
							xPosition = x;//move
							yPosition = y;
							start = false;
						}
						success = true;
						if(positions[y][x] > NoPiece)
						{
							death = true;//if it kills change death
						}
					}
				}
				else if(team == 1)
				{
					if(positions[y][x] <= NoPiece)
					{
						if(!check)
						{
							xPosition = x;
							yPosition = y;
							start = false;
						}
						success = true;
						if(positions[y][x] < NoPiece)
						{
							death = true;
						}
					}
				}
			}
			else if(start == true && inBetween(positions, x, y) && positions[y][x] == NoPiece)//getting ready to castle
			{
				if(y == yPosition + 2)
				{
					castling = 1;
				}
				else if(y == yPosition - 2)
				{
					castling = 2;
				}
			}
			return success;
		}
		void setStart(bool newStart)
		{
			start = newStart;
		}
		bool getStart()
		{
			return start;
		}
		bool hasStart()
		{
			return true;
		}
		int isCastling()
		{
			return castling;
		}
	private:
		bool start;//whether or not it has moved yet
		int castling;//whether or not the king is trying to castle
		//pieceType type;
		//bool alive;
		//int team;
		//int xPosition;
		//int yPosition;
};

#endif;