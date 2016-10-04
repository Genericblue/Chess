#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
	public:
		//constructor
		Pawn(int newTeam, int x, int y)
		{
			start = true;
			alive = true;
			moved = false;
			team = newTeam;
			xPosition = x;
			yPosition = y;
			if(team == 0)
			{
				type = PawnPiece0;
			}
			else
			{
				type = PawnPiece1;
			}
		}
		//destructor
		~Pawn()
		{

		}
		//move function
		bool move(pieceType positions[8][8], int x, int y, bool &death, bool check)
		{
			bool success = false;
			if(team == 0)//player 1
			{
				if(x == xPosition+1 && y == yPosition && positions[y][x] == NoPiece)//moving one space
				{
					if(!check)
					{
						xPosition = x;//move
						start = false;//set start to false
					}
					success = true;
				}
				else if(x == xPosition+2 && y == yPosition && inBetween(positions, x, y) && positions[y][x] == NoPiece && start == true)//making start move
				{
					if(!check)
					{
						xPosition = x;
						start = false;
						moved = true;
					}

					success = true;
				}
				else if(((x == xPosition+1 && y == yPosition+1) ||
						(x == xPosition+1 && y == yPosition-1)) &&
						positions[y][x] > NoPiece)//attacking diagonally
				{
					if(!check)
					{
						xPosition = x;
						yPosition = y;
						start = false;
					}
					death = true;
					success = true;
				}
			}

			else if(team == 1)
			{
				if(x == xPosition-1 && y == yPosition && positions[y][x] == NoPiece)
				{
					if(!check)
					{
						xPosition = x;
						start = false;
					}

					success = true;
				}
				else if(x == xPosition-2 && y == yPosition && inBetween(positions, x, y) && positions[y][x] == NoPiece && start == true)
				{
					if(!check)
					{
						xPosition = x;
						start = false;
						moved = true;
					}

					success = true;
				}
				else if(((x == xPosition-1 && y == yPosition+1) ||
						(x == xPosition-1 && y == yPosition-1)) &&
						positions[y][x] < NoPiece)
				{
					if(!check)
					{
						xPosition = x;
						yPosition = y;
						start = false;
					}

					death = true;//if it kills change death
					success = true;
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
		bool getMoved()
		{
			return moved;
		}
		void setMoved(bool newMoved)
		{
			moved = newMoved;
		}
	private:
		bool start;//for if the pawn has used its starting move
		bool moved;//for if the pawn just moved (for en passant)
		//pieceType type;
		//bool alive;
		//int team;
		//int xPosition;
		//int yPosition;
};

#endif;