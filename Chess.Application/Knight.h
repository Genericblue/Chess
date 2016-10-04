#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight: public Piece
{
	public:
		//constructor
		Knight(int newTeam, int x, int y)
	{
		alive = true;
		team = newTeam;
		xPosition = x;
		yPosition = y;
		if(team == 0)
		{
			type = KnightPiece0;
		}
		else
		{
			type = KnightPiece1;
		}
	}
		//destructor
		~Knight()
	{

	}
		//move function
		bool move(pieceType positions[8][8], int x, int y, bool &death, bool check)
		{
			bool success = false;
			if( ((x == xPosition - 2) && (y == yPosition - 1 || y == yPosition + 1)) ||
				((x == xPosition + 2) && (y == yPosition - 1 || y == yPosition + 1)) ||
				((y == yPosition - 2) && (x == xPosition - 1 || x == xPosition + 1)) ||
				((y == yPosition + 2) && (x == xPosition - 1 || x == xPosition + 1)))//figures out if it is trying to move in an "L"
			{
				if(team == 0)//player 1
				{
					if(positions[y][x] >= NoPiece)
					{
						if(!check)
						{
							xPosition = x;//move
							yPosition = y;
						}
						success = true;
						if(positions[y][x] > NoPiece)
						{
							death = true;//if it kills something change death
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