set style fill solid
set tics font "Times New Roman, 14"
set title "Spectrum" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Spectrum" font "Times New Roman, 14"
plot "sp.dat" with boxes
pause -1 "press [Enter] key to next"
set title "Angle" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Angle" font "Times New Roman, 14"
plot "rad.dat" with boxes
pause -1 "press [Enter] key to next"
set title "Input wave" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Hight" font "Times New Roman, 14"
plot "input.dat" with lines
pause -1 "press [Enter] key to next"
set title "Mixed wave" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Hight" font "Times New Roman, 14"
plot "f00" with lines,\
	"f01" with lines, \
	"f02" with lines, \
	"f03" with lines, \
	"f04" with lines, \
	"f05" with lines, \
	"f06" with lines, \
	"f07" with lines, \
	"f08" with lines, \
	"f09" with lines, \
	"f10" with lines, \
	"f63" with lines
pause -1 "press [Enter] key to quit"

