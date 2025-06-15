#include "Colors.h"



const Color maroon = { 30, 30, 60, 255 };
const Color green = { 144, 238, 144, 255 };
const Color red = { 255, 80, 80, 255 };
const Color orange = { 255, 165, 0, 255 };
const Color yellow = { 255, 255, 140, 255 };
const Color purple = { 190, 90, 255, 255 };
const Color cyan = { 100, 255, 255, 255 };
const Color blue = { 100, 149, 237, 255 };
const Color lightBlue = {59 , 85 ,162 , 255};
const Color BackColor = { 10, 10, 30, 255 };
const Color BombColor = { 0 ,0 ,0 ,255 };

std::vector<Color> GetCellColors() {

	return { maroon , green , red , orange ,yellow , purple ,cyan , blue , BombColor};
}
