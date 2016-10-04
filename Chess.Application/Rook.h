#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
	public:
		//constructor
		Rook(int newTeam, int x, int y, bool newStart)
		{
			alive = true;
			start = newStart;
			team = newTeam;
			xPosition = x;
			yPosition = y;
			if(team == 0)
			{
				type = RookPiece0;
			}
			else
			{
				type = RookPiece1;
			}
		}
		//destructor
		~Rook()
		{

		}
		//move function
		bool move(pieceType positions[8][8], int x, int y, bool &death, bool check)
		{
			bool success = false;
			if(x == xPosition || y == yPosition)//moving in straight lines
			{
				if(team == 0)//player 1
				{
					if(inBetween(positions, x, y) && positions[y][x] >= NoPiece)//no piece inbetween
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
					if(inBetween(positions, x, y) && positions[y][x] <= NoPiece)
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
	private:
		bool start;//whether or not it has moved yet
		//pieceType type;
		//bool alive;
		//int team;
		//int xPosition;
		//int yPosition;
};

#endif;