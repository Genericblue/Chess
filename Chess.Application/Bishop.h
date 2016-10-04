#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{

	public:
		//constructor
		Bishop(int newTeam, int x, int y)
		{
			alive = true;
			team = newTeam;
			xPosition = x;
			yPosition = y;
			if(team == 0)
			{
				type = BishopPiece0;
			}
			else
			{
				type = BishopPiece1;
			}	
		}
		//destructor
		~Bishop()
		{

		}
		//move function
		bool move(pieceType positions[8][8], int x, int y, bool &death, bool check)
		{
			bool success = false;
			if((x != xPosition && y != yPosition) && 
				(y == yPosition + (x - xPosition) || y == yPosition - (x - xPosition)))//is it moving diagonally
			{
				if(team == 0)//player 1
				{
					if(inBetween(positions, x, y) && positions[y][x] >= NoPiece)//nothing in between
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