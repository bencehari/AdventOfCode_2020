#ifndef __input_h__
#define __input_h__

/*const char* input[] = {
	"L.LL.LL.LL",
	"LLLLLLL.LL",
	"L.L.L..L..",
	"LLLL.LL.LL",
	"L.LL.LL.LL",
	"L.LLLLL.LL",
	"..L.L.....",
	"LLLLLLLLLL",
	"L.LLLLLL.L",
	"L.LLLLL.LL"
};*/

const char* input[] = {
	"LLLLLLLL.LLL.LLLLLLLLLLLLL.LL.LLLLLL.LL.LLLLLLLLLLLLLL.LLLLLLL.LLLLLLLLLLLLLLLLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLLLLLLL.LLLLLLLLL.LLLLLL.LLLLLL.LL.LLLLLLL.LLLLLL.LLLLLLLLL.LLLL.LLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.LLL.LLLLLLLLLLLL.LLL..LLLLLL.LLLLL.LLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LL.L.LLLLLLLLLLLLLLLL..LLLLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLLLLLL.LLLLLLLLLLLLLL",
	"LLLLLLL.LLLLLLLLLLL.LLLLLLLLL.L.LLLLLLLLLLLLL..LLLLLLL.LLLLLL.LLLLL.LLLLLLLLLLLLLL.LL.LLLLL",
	"..L.L...L....L......LL.LLL..L.L.L.L...L.........LLLL..L..L...LL..L.L.L.....LLLLL..L..L..L..",
	"LLLLLLLL..LLLLLLLLLLLLLLLLLLL.LLLLLLLLL.LLLLLL.LLLLLLL.LLLLLLLLLLLLLLLL.LLL.LLLLLL.LLLLLLLL",
	"LLLLLLLLLLLLLLLLLL..LLLLLLLLL.LLLLLLLLLL.LL.LLLLL.LLL..LLLLLLLLLLL..LLLL.LLLLLLLLL.LLLLLLLL",
	"LLLLLLLLLLLLLL.L.LL.LLLLLLLLL.LLLLLL.LLLLLLLLL.LLLLL.L.LLLLLL.LLLLLLLLLLLLLLLLL.LL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLLLL.L..LLLLLLLLLL.LLLLL.LLLLLL.LLLLLL.L.LLLLLLLLLLLL.LLLLL.LLL.LLLL",
	"LLL.LLLL.LLLLL.LLLL.LLLLLLLLL.LLLLLL.LLLLLLLLL.LLLLLLLLLLLLLL.LL.LL.LLLLLLLLLLLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLLLLLL.LLLLL.LLLLLL.L.LLLLLLL..LLLL.L.LLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLL",
	"LLLLLLL.LLLLLL.LL.L.LLLLLLLL..LLLLLLLLLLLLL.LLLLLLLLLL.LL.LLL.LLLLL.LLLLLL.L.LLLL..LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL..LLLLLLLL.LLLLLL.LLLLLLLLL.LLLLLLL.LLLLLL.LLLLLLLLLLL.LL..LLLL.LLLLLLLL",
	"LLLLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLL.LLLLLLL..L.LLLLLLLLLLLL.LLLLL.LLLLLL.L.LLLLL.LLLLLLLL",
	".L.LL....LLL..L.......L...LLLL..LLL....L..L...L.....L...L...LL......L.....L......L........L",
	"LLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLL...LLLLLLLL.LL.LLLL.LLLLL..LLL.L.LLLLLLLL.LLLLLLLLLLLL.L",
	"LLLLLLLL.LLLL.LLLLL.LLLLLLLLL.LL.L.LLLLLLLLLL..LLLLLLLLLLLLLL.LLLLL.LLLLLLLL.LLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLLLLLLLLLLLL.LLLLL.LLLLLLLLLL.LLLLLLL.LL.LLL.LLLLLLLLLLLLLL.LLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLLLLLL..LLLLL.LLLLLLLLLLLLLLLLL.LLLLLL.LL.LLLLLLLL.LL.LLLLL.LLLLLL.L",
	".LLLLLLLL.LLLL.LLLL.LLLLLLLLL.L.LLLL.LLLLLLLL..LL.L.LL.LLLLLL.L.LLL.L.LL.LL..LLLLL.LLLLLLLL",
	"LLLLL.LLLLLLLL.LLLL.LLLLLLLLL.LLLLL.LLLLLLLLLL.LLL.LLLLLLLLLL.LLLLL.LLLLLLLL.LLLLLLLLLL.LLL",
	"L..L.L..L....L....L.....LL.L.LL.L...L.L.LL..LL.L.....L.L...L....LL.L....LL........L..LL...L",
	"LLLLLLLL.LLLLL.LLLLLLL.LLLLLL.LLLLLL.LLLLLLLLL.LLLLLLLLLLLLLLLLLLLL..LLLL.LL.LLLLLLLLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLL.L.LLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLL..LLLLL.LLLLLLLL.LLLL..L.LLLLLL",
	"LLLLLLLL...LLL.LLLL..LLLLLLL..LLLLLL.L.LLLLLLLLLLL.LLLLLLLLLL.LLLLL.LLLLLLLL.LLLLLLLLLLLLLL",
	"LLL.LLLL.LLLLLLLLLL.LLLLLLLLL.LLLLLLLLLLLLLLLL.LLLL.LL.LLLLLLLLLLLL.LLLLLLLL.LLLLL.LLL..LLL",
	"LLLLLLLLLLLLLL.LLLL.LLLLL.LLLLLLLLLL.LLLLLLLLLLLLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLLL.LLLLLLLL",
	"LL.LL.LLLLLLLLLLLLLL.LLLLLLLL.LLLLLLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLLLLLLLLL.LLLLLLLLLLL",
	"LLLL.LLL.L.LLL.LLLL.LLLLLLLLL.L.LLLL.LLLLL.LLL.LLLLL.L.LLLLLL.LLLLL.LLLLLLLL.LLLLLLLLLLLLLL",
	".L........L...L.....LL..L..L......L.L.LLL.L.LL..LL....LLL..L.L..LLLL...LLLL...L..........LL",
	"LLLLLLL.LLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLL.LLLLL.LLLL.LLLLLL.LLLLL.LLLLLLLL.LLLLL.LLLLLLL.",
	"LLLLLLLL.LLLLL..LLL.LLLLLLLLL.LLLLLL.LLLLLLLL..LLLLLLL.LLLLLL.LLLLLLLLLLLLLLLL.LLL.LLLLLLLL",
	"LLLLLLLL.LLLLLLL.LL.LLLLLLLLLLLLLLLLLLLLLL.LLL.LLLLLLL.LLLLLL.LLLLL.LLLLLLLLL.LLLL.LLLLLLLL",
	".LLLLLLL.LLLLL.LLLL.LLLLLLLLLLLLLLLL.LLLLLLLLL.LLLLLLL.LL.LLL.LLLLLLLLLLLLLLLLLLLL.LLLLLLLL",
	"LLL.LLLL.LLLLL.LLLL.LLLLLLLLL.LLLLLL.LLLLLLL.L.LLLLLLL.LLLLL...LLLL.LLLLLLLL.LLLLL.LLLLLLLL",
	"LLLLLLLL.LLL.L.LLLLLLLLLLLLLL.LLLLLLLLLLL.LLLL.LLLLLLL.LLLLLL.LLLLL.LLLLLLLLLL.LLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.L.LLLLLLLLLLLLLL.LLL.LLLLL.LLLL.LL.LLLLLLL.LL.L.LLLLLLLL.LLL.L.LLLLLLLL",
	".LLLLLLLLLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLLL.L.LLLLLLL.LLLLLL.LLLLL.LLLLLLLLLLLLLLLLLLLLLLL",
	"LLLLLLLL.LLLLLLLLLL.LLLLLLL.LLL.LLLLLLLLLLLLLLLLLLL.LL.LLLLLLLLLLLL.LLLL.LLL.LL.LL.LLLLLLLL",
	".L....L........L.L.L......LL..L.L.L...LLLL.....L...L..........LL.LLLL.L...L.L.LL.LL.L...L.L",
	"LLLLLLLL.LLLL.LLL.L..L.LLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL.L.LLLLLLLLLLLLLLLLLLLL.LLLLLLLL",
	"LLLL.LLL.LLLL..LLLL.LL.LLLL.LLLLLLLL.LLL.LLLLLLLLLLLLLLLLLLLL.LLLLL.LLLLLLL..LLLL.LLL.LLLLL",
	"LLLLLLLL..LLLLLL.LL.LLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLL.LLLLLL.LLLLL.LLLL.LLL.LLLLL.LLLLLLLL",
	"LLLLLLLLLLLLLLL.LLLLLLLLLLLLL.LLLLLLLLLLLLL.LLLLLLLLLL.LLL.LL..LLLLLLLLLLLLL.LLL.L.LL.L.LLL",
	"LLLLLLLLLLLLL..LL.LLLLLLLLLLLLLLLLLL.LLLLLLLLL.LLLLLLL.LLLLLL.LLLLL.LLLLLLLL.LLLLLLLLLLLLLL",
	"LLL.LLLL.LLLLL.LLLL..LLLLL.LLLLLLLLL.LLLL..LLLLLLLLLL..LLLLLLLLLLLL.LLLLLLLLLLLLLL.LLL.LLLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLLLLLL.LLLLLL.LLLLLLLLL.LLLLLLL.LLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLLLLLL",
	"L.L.LLLL.LLLLL.LL.L.LLLLLLLLLLLLLLLLLLLLLL.LLLLLLLLLLL.LLLLLLLLL.LLL.LLLLLLLLLLLLLLLLLLLLLL",
	"..LLLL.........L.LL.LL....L.LL...LLLL....L...L........LL...L.L......L.LLL.L.L...LL....L...L",
	"LLLLLLLL.LL.LL.LLLL.LLLL.LLLLLLL.LLL.LLLLLLLLL.LLLLLL.LLLLLL..LLLLL.LLLLL.LLLLLLLLLLLLLLLLL",
	"LLLLLL.LLLLLLL.LLLL.LLLLLLLL.LLLLLLLLLLLLLLLLL.LLLLLL..LLLLLL.L.L.L.LLL.LLLLLLLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LL.L.LLLLLLLLLLLLLLLLLLLLLLLL.L.LLLL.LL.LLLLLL.LLLLL.LLLLLLLL..LLLL.LLLLLLLL",
	"LLLLL.LL.LLLLL.LLLLLLLLLLLLLLLLLLLLL.L.LLLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLLL",
	"LLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLL.LLLLLLL.LLLLLL.LLLL.LLLLL..LLLLL.L.LLLLLL.LLLLL.LLLLLLLL",
	"LLLLLLLLLLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLL.LLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLLLLLL.LLLLLL.LLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLL.LLLLLLLL",
	"L.....LL..L..L.L..L....L.L......LL..L......L.LL..L..L..L...L..L...L.....L......LLLLLL......",
	"LLLLL.LLLLLLLLLLLLL.LLLLLLLLLLLLLLLL..LLLLLLLLLLLLLLLL.LLLLL.L.LLLL.LLLLLLLL.LLLLL.LLLLLLL.",
	"LLLLLLLL.LLLLL.LLLL.LLLLLL.LL.LLLLLL.LLLLLLLLL.LLLLL.L.LLLLLL.LLLLL.LLLL.LLL.LLLLLLLLLLLLL.",
	"LL.LLLLL.LLLLL.LLLL.LLLLLLLLLL.LLLLLLLLLLLLLLL.LLLLLLL..LLLLLLLLLLLLLLLLLLLL.LLLLL.LLLLLLLL",
	".LLLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLL.LLLLLL.LLLLL.LLLLLLLL.LLLLLLLLLLLLLL",
	"L....L.LL.LLL.L...LL.L....LL..........L.L..L.....LL...L.....LL......L...LLLL.L.....L.LL.L..",
	"LLLLLLLL.LLL.LLLL.L.LLLLLL.LL.LLLLLL.LLLLLLLLLLLLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLLL.LLL.LLLL",
	"LL.LLLL..LLLLL..LLL.LLLLLLLLL.LLLLLL.LLLLLLLLL.LLLLLL..LLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLL.LLL",
	"LLLLLL.L.LLL.L.L.LL.LLLLLLLLLLLLLLLL.LLLL.LLLL.L..L.LL.LLLLLL.LLLLLL.LLLLLLL.LLLLL..LLLL.LL",
	"LLLLLLLL.LLLLL.LLLLLLLLLLLLLLLLLLLLL..LLLLLLLL...LLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLLLL",
	"LLLLLLLL.LLLLL.LL.L.LLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLL.LLL.LLLLL.LLLLLLL..LLLLL.LLLLLLLL",
	"LLLLLL.LLLLLLL..LLLLLLLLLL.LLLLLLLLL.LLLLLL.LL.LLLLLLL.LLLLLL.LLLLLLLLLL.LLLLLLLLLL.LLLLLLL",
	"L......L....L...L..L...L..L.LLL.LLLL....L...L.L.L....L..L...LLL.LLL...L......LL....L...L.LL",
	"LLLLLLLL.LLLLL.LLL..LL.LLLLLLLLLLLLL.LLLLLLLLL.LLLLLLLLLLLLL..L.LLLLLLLLLL.LLLLLLLL.LLLLLLL",
	"LLLLLLLL.LLLLLLLLLL.LLLLLLLLL.LLLLLL.LLLLLLLLLLLLLLLLL.LLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLLLLLLLLL.LLLLLLLLLLLLL.LLLLLLL.LLLLLL.LLLLLLLLLLLLLLLLLLL..LLLLLLLL",
	"LLLLLLLLLLL.LLLLLLL.LLLLLLLLLLLLLLLL.LLLLLLLLLLLLLLLLL.LLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLLL",
	"LLLL.LLL.LLLL..LLLL.L.L.LLLLL.LL.L.L.LLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLL.LLLLLLLL",
	"LLLLLLLLLLLLLLLLLL..L.LLLLLLLLLLLLLLLL.LLLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLLLLLLLLLLLLL.LLLLLLL",
	"LL.LLLLL.LLLLL.LLLL.LLLLLLLLLLLLLLLLLLLLLLLL.LL.LLLLLLLLLLLL..LLLLL.LLLLLLLL.LLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLLLLLLLLLLLL.LLLLLL.LLLLLLLLL.LLLLLLL.LLLLLLLLLLLLLLLLLL.LL.LLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLL.LLL.LLLLLLLLLL.LLLLLLLLLLLLLLL..LLLLLLL.LLLLLL.LLLLL.LLLLLLLL.LLLLL.LLLLLLLL",
	".LLL.L..L...L.L...L...LL.L..LL.L...LLL.L.L...L...L.LLL..L.......L....L..L......LL..........",
	"LLLLLLLL.LLLLL.LLLL.LL.LLLLLLLLLLLLL.LLLLLLLLL.L.LLLLL.LLLLLL.LLLLL.LLLLLLLL.LLLLL.LLLLLLLL",
	"LLLLLLLL.LLLLLLLL.LLLLLLLLLLL.LLLLLLLLLLLLLLLL.LLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLL..LLLL.LL.",
	"LLLLLLLL.L.LLLLLLLLLLLLLLLLLLLLL.LLL..LLLLLLLL.LLLLLLL.LLL.LLLLLLLL.LLLLLLLL.LLLL..LLLLLLLL",
	"LLLLLLLL.LLLLL.LLLL.LLLLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LL.LLLLLLLLLLLLLLLLLLL.L..LLLL.LLLLLLLL",
	"LLL.LLLL.LLLLL.LLLL.LLLLLLL.LLLLLLLL.LL.LLLLLL.LLLLLLL.LLLLLL.LLLLL.LLLLLL.L.LLLLLLLLLLLLLL",
	"LL.LLLLL.L.LLL.LLLL.L.LLLLLLLLLLLLLL..LLLLLLLL.LLLLLLL.L.LLLL.LLL.L.LLLLLLLLLLLLLL.LLLLLLLL",
	"LLLLLLLLLLLLLL.LLLL.LLLLLLLLL.LLLLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLLL.LLLLLLLLLLLLLLLLLLLLLLL",
	"LL.LLLLL.LL.LLLLLLL.LLLLLLLLL.LLLL.L.LLLLLLLLL.LLLLLLL..LLLLL.LLLLL.LLLLLLLLLLLLLL.LLL.LLLL",
	"LLLLLLLL.LLLLLLLLLL.LLLLLLLLL.LLLL.L.LLLLLLLLL.LLLL.LLLLLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLLL"
};

#endif
