#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
	public:
		//constructor
		Queen(int newTeam, int x, int y)
		{
			alive = true;
			team = newTeam;
			xPosition = x;
			yPosition = y;
			if(team == 0)
			{
				type = QueenPiece0;
			}
			else
			{
				type = QueenPiece1;
			}	
		}
		//destructor
		~Queen()
		{

		}
		//move function
		bool move(pieceType positions[8][8], int x, int y, bool &death, bool check)
		{
			bool success = false;
			if(x == xPosition || y == yPosition)//not moving diagonally
			{
				if(team == 0)//player 1
				{
					if(inBetween(positions, x, y) && positions[y][x] >= NoPiece)//if no piece in between
					{
						if(!check)
						{
							xPosition = x;//move
							yPosition = y;
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
					if(inBetween(positions, x, y) && positions[y][x] <= NoPiece)
					{
						if(!check)
						{
							xPosition = x;
							yPosition = y;
						}
						success = true;
						if(positions[y][x] < NoPiece)
						{
							death = true;
						}
					}
				}
			}
			else if((x != xPosition && y != yPosition) && 
				(y == yPosition + (x - xPosition) || y == yPosition - (x - xPosition)))//moving diagonally
			{
				if(team == 0)
				{
					if(inBetween(positions, x, y) && positions[y][x] >= NoPiece)
					{
						if(!check)
						{
							xPosition = x;
							yPosition = y;
						}
						success = true;
						if(positions[y][x] > NoPiece)
						{
							death = true;
						}
					}
				}
				else if(team == 1)
				{
					if(inBetween(positions, x, y) && positions[y][x] <= NoPiece)
					{
						if(!check)
						{
							xPosition = x;
							yPosition = y;
						}
						success = true;
						if(positions[y][x] < NoPiece)
						{
							death = true;
						}
					}
				}
			}
			return success;
		}
	private:
		//pieceType type;
		//bool alive;
		//int team;
		//int xPosition;
		//int yPosition;
};

#endif;