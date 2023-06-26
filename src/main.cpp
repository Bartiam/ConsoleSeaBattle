#include <iostream>

const int ROW = 10;
const int COL = 10;

class gamer
{
public:
	gamer() {++count;}

	static int getCount() { return count; }
	bool getCoordinateOfField(int x, int y) {return Gamer[x][y];}
	void setCoordinatesOfField(int x, int y) { Gamer[x][y] = true; }

private:
	bool Gamer[ROW][COL]{};
	static int count;
};
int gamer::count = 0;

void setup(gamer& oneOfThem)
{
	int x, x1, y, y1, countShips = 0;
	while (countShips != 10)
	{
		std::cout << oneOfThem.getCount() << " Gamer. " << "Please specify the origin of the ship's coordinates(0 - 9): ";
		std::cin >> x >> y;

		std::cout << oneOfThem.getCount() << " Gamer. " << "Please indicate the end of the coordinates of the ship(0 - 9): ";
		std::cin >> x1 >> y1;

		if ((x < 0 || x > 9) || (y < 0 || y > 9))
			std::cout << "You have gone out of bounds! Try again!" << std::endl;
		else
		{
			for (int i = x; i <= x1; ++i)
			{
				for (int j = y; j < y1; ++j)
				{
					if ((i >= x && j >= y) && (i <= x1 && j < y1))
						if (oneOfThem.getCoordinateOfField(i, j)) 
							std::cout << "Error! Here is already full field! " << std::endl;
						else oneOfThem.setCoordinatesOfField(i, j);
				} 
			}
		}
		break;
	}

	
}

void draw(gamer& firstGamer, gamer& secondGamer)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (firstGamer.getCoordinateOfField(i, j)) std::cout << "S" << " ";
			else std::cout << "O" << " ";
		}
		std::cout << "\t";
		for (int j = 0; j < 10; ++j)
		{
			if (secondGamer.getCoordinateOfField(i, j)) std::cout << "S" << " ";
			else std::cout << "O" << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	gamer firstGamer;

	std::cout << "You can only setup such ships: \n" <<
		"One very large ship(It consists of four cells)\n" <<
		"Two large ships(It consists of three cells)\n" <<
		"Three medium ships (It consists of two cells)\n" <<
		"Four little ships (It consists of one cell)\n" << std::endl;

	setup(firstGamer);
	gamer secondGamer;
	//setup(secondGamer);
	draw(firstGamer, secondGamer);

	

	return 0;
}
