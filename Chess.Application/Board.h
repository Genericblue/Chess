#ifndef BOARD_H
#define BOARD_H

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board
{
	public:
		//constructor
		Board()
		{
			int t = 0, y = 0, x = 1, i = 0;
			//pawn
			for(t = 0; t < 2; t++)//team for piece
			{
				for(y = 0; y < 8; y++)//y position for piece
				{
					pieces[i] = new Pawn(t,x,y);
					i++;
				}
				x = 6;//xpositon for other team
			}
			x = 0;//xposition for next piece
			//Rook
			for(t = 0; t < 2; t++)
			{
				for(y = 0; y < 8; y = y+7)
				{
					pieces[i] = new Rook(t,x,y, true);
					i++;
				}
				x = 7;
			}
			x = 0;
			//Knight
			for(t = 0; t < 2; t++)
			{
				for(y = 1; y < 8; y = y+5)
				{
					pieces[i] = new Knight(t,x,y);
					i++;
				}
				x = 7;
			}
			x = 0;
			//Bishop
			for(t = 0; t < 2; t++)
			{
				for(y = 2; y < 8; y = y+3)
				{
					pieces[i] = new Bishop(t,x,y);
					i++;
				}
				x = 7;
			}
			x = 0;
			//Queen
			for(t = 0; t < 2; t++)
			{
				for(y = 4; y < 8; y = y+8)
				{
					pieces[i] = new Queen(t,x,y);
					i++;
				}
				x = 7;
			}
			x = 0;
			//King
			for(t = 0; t < 2; t++)
			{
				for(y = 3; y < 8; y = y+8)
				{
					pieces[i] = new King(t,x,y);
					i++;
				}
				x = 7;
			}

			update();
		}
		//destructor
		~Board()
		{

		}
		//updates the positions array
		void update()
		{
			int x = 0, y = 0, i = 0; 
			bool empty = true;
			for(x = 0; x < 8; x++)//walk through x positions
			{
				for(y = 0; y < 8; y++)//walk through y positions
				{
					for(i = 0; i < 32; i++)// walk through pieces
					{
						if(pieces[i]->getX() == x && pieces[i]->getY() == y)
						{
							//if the piece is at the x and y positions
							//then set the positions[y][x] to the type of the piece
							positions[y][x] = pieces[i]->getType();
							empty = false;
						}
					}
					if (empty == true)
					{
						//otherwise set it to no piece
						positions[y][x] = NoPiece;
					}
					empty = true;
				}
			}
		}
		//searches for the piece at the xy position or the x and y position of the piece(king usually)
		//returns -1 if it is unable to find the piece
		int search(int &x, int &y, pieceType piece)
		{
			if (nullptr == pieces) 
			{
				return -1; 
			}

			int i = 0, j = -1;

			if(piece == NoPiece)
			{
				for(i = 0; i < 32; i++)
				{
					if(pieces[i]->getX() == x && pieces[i]->getY() == y)
					{
						j = i;
					}
				}
				return j;
			}
			else
			{
				for(i = 0; i < 32; i++)
				{
					if(pieces[i]->getType() == piece)
					{
						x = pieces[i]->getX();
						y = pieces[i]->getY();
					}
				}
			}
			
		}
		//interprets the intended move and moves the piece
		bool move(int team, int x, int y, int x2, int y2, int &status)
		{
			int a = 0, b = 0;
			//grabs the piece at x and y
			int i = search(x,y, NoPiece);
			//grabs the piece at x2 and y2
			int j = search(x2,y2, NoPiece);
			int k = 0;
			bool death = false, success = false;
			//if the search is successful and the piece is the right team
			if(i != -1 && pieces[i]->getTeam() == team)
			{
				//En Passante check
				//if the piece being moved is a pawn check for en passante
				if((pieces[i]->getType() == PawnPiece0 || pieces[i]->getType() == PawnPiece1)
					&& x2 == x - (2*(team)-1))
				{
					//set k to the piece next to the pawn
					k = search(x,y2, NoPiece);
					//if that piece has just made its first move
					if(k != -1 && k != i && pieces[k]->getMoved() == true)
					{
						//move the piece to where the first pawn will move
						//so it kills it
						pieces[k]->setX(x2);
						j = k;
					}
					update();
				}

				//success equals the output of the pieces own move function
				success = pieces[i]->move(positions, x2, y2, death, false); ////

				//castling check, if piece is castling(castling != 0) and it isnt in danger, begin
				if(pieces[i]->isCastling() != 0 && !danger(x,y,team))
				{
						//set k to the rook on the right side
						k = search(x, y += 4, NoPiece);
						y -= 4;
						//set the king to the spot to the right
						pieces[i]->setY(y+1);
						update();
						//if k is found, the king is casling to the right, isnt in danger on the way
						//the piece found is an allied rook, and it hasn't moved yet, then castle
						if(k != -1 && pieces[i]->isCastling() == 1 && !danger(x,y+1,team) 
							&& (pieces[k]->getType() == RookPiece0 || pieces[k]->getType() == RookPiece1) && pieces[k]->getTeam() == team 
							&& pieces[k]->getStart() == true)
						{
							//move the king one more space
							pieces[i]->setY(y+2);
							update();
							//check to see if it is in dager there
							if(!danger(x,y+2,team))
							{
								//if not then move the rook
								pieces[k]->setY(y+1);
								pieces[i]->setStart(false);
								pieces[k]->setStart(false);
								success = true;
							}
							else
								//if not move the king back
								pieces[i]->setY(y);
						}
						else
							pieces[i]->setY(y);

						//do this again for the left
						k = search(x, y -= 3 , NoPiece);
						y += 3;
						if(pieces[i]->isCastling() != 1)
						{
							pieces[i]->setY(y-1);
							update();
						}
						if(k != -1 && pieces[i]->isCastling() == 2 && !danger(x,y-1,team)
							&& (pieces[k]->getType() == RookPiece0 || pieces[k]->getType() == RookPiece1) && pieces[k]->getTeam() == team
							&& pieces[k]->getStart() == true)
						{
							pieces[i]->setY(y-2);
							update();
							if(!danger(x,y-2,team))
							{
							pieces[k]->setY(y-1);
							pieces[i]->setStart(false);
							pieces[k]->setStart(false);
							success = true;
							}
							else
								pieces[i]->setY(y);
						}
						else if(pieces[i]->isCastling() != 1)
							pieces[i]->setY(y);
				}
				
				//if death (passed into move) comes back true
				if(death)
				{
					//then set the alive variable = false
					pieces[j]->setAlive(false);
					//and move the piece to -1,-1
					pieces[j]->setX(-1);
					pieces[j]->setY(-1);
				}
				update();

				if(!success)
				{
					status = 3;//Invalid move
				}

				//find the appropirate team's king piece
				if(team == 0)
					search(a,b,KingPiece0);
				else
					search(a,b,KingPiece1);

				if(danger(a,b,team))//if the king is in check
				{
					status = 4;//Your King is in check
					//reset everything, move the piece back to where it was
					pieces[i]->setX(x);
					pieces[i]->setY(y);
					if(death)
					{
						//bring the other piece back to life if need be
						pieces[j]->setAlive(true);
						pieces[j]->setX(x2);
						pieces[j]->setY(y2);
					}
					if(pieces[i]->hasStart() == true)//broken//////////////////////////////////////////////////////////
					{
						pieces[i]->setStart(true);
					}
					success = false;
				}
			}
			else//error notices
			{
				if(i == -1)
				{
					status = 1;//No piece there
				}
				else if(pieces[i]->getTeam() != team)
				{
					status = 2;//Not your piece
				}
			}

			return success;
		}
		//getter for positions
		pieceType getPositions(int y, int x)
		{
			return positions[y][x];
		}
		//replaces the pawn
		void replacePawn(int replace, int x, int y, int team)
		{
			int i = search(x,y, NoPiece);//finds the pawn
			delete pieces[i];//deletes the pawn
			if(replace == 1)
			{
				pieces[i] = new Queen(team, x, y);//replaces with Queen
			}
			else if(replace == 2)
			{
				pieces[i] = new Bishop(team, x, y);//with Bishop
			}
			else if(replace == 3)
			{
				pieces[i] = new Knight(team, x, y);//with Knight
			}
			else if(replace == 4)
			{
				pieces[i] = new Rook(team, x, y, false);//with Rook
			}

		}
		//checks to see if the piece at the coordinates is in danger
		bool danger(int x, int y, int t)
		{
			int  i = 0;
			bool death = false;
			for(i = 0; i < 32; i++)//walk through the pieces
			{
				if(pieces[i]->getTeam() != t && pieces[i]->getAlive() != false)//if an enemy piece that is alive
				{
					pieces[i]->move(positions, x, y, death, true);//can kill the piece at the spot
					if(death)
					{
						return true;//then return true
					}
				}
			}
			return false;//else
		}
		//checks to see if checkmate
		bool checkmate(int t)
		{
			int x = 0, y = 0, x2 = 0, y2 = 0, i = 0, j = 0, a = 0, b = 0;
			bool death = false, check = true, start = true;
			for(x2 = 0; x2 < 8; x2++)//walk through x2
			{
				for(y2 = 0; y2 < 8; y2++)//walk through y2
				{
					for(i = 0; i < 32; i++)//walk through pieces
					{
						if(pieces[i]->getTeam() == t && pieces[i]->getAlive() != false)//if an allied piece that is alive
						{
							death = false;
							start = true;
							//search for piece at x2 y2
							j = search(x2,y2, NoPiece);
							//set x and y to the coordinate of orignal piece
							x = pieces[i]->getX();
							y = pieces[i]->getY();

							if(pieces[i]->hasStart())//to perserve a pieces start
							{
								start = pieces[i]->getStart();
							}

							//move the piece to test
							pieces[i]->move(positions, x2, y2, death, false);

							//to perserve start
							if(pieces[i]->hasStart() && start != pieces[i]->getStart())
							{
								pieces[i]->setStart(true);
							}
							
							//to reset for en passant
							pieces[i]->setMoved(false);

							if(death)//death function
							{
								pieces[j]->setAlive(false);
								pieces[j]->setX(-1);
								pieces[j]->setY(-1);
							}
							update();

							if(t == 0)//find king piece
								search(a,b,KingPiece0);
							else
								search(a,b,KingPiece1);

							if(!danger(a,b,t))//see if it is in danger
							{
								check = false;// if it isnt then it isnt checkmate
							}

							//reset everything
							pieces[i]->setX(x);
							pieces[i]->setY(y);
							if(death)
							{
								pieces[j]->setAlive(true);
								pieces[j]->setX(x2);
								pieces[j]->setY(y2);
							}
							
							update();

						}
					}
				}
			}
			return check;
		}
	private:
		Piece *pieces[32];// an array of pointers to all 32 of the pieces
		pieceType positions[8][8];//a 2d array of pieceTypes to resemble the board
};

#endif;
