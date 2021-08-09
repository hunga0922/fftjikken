set term png
set style fill solid
set tics font "Times New Roman, 14"
set title "Spectrum" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Spectrum" font "Times New Roman, 14"
set output "sp.png"
plot "sp.dat" with boxes
set title "Angle" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Angle" font "Times New Roman, 14"
set output "rad.png"
plot "rad.dat" with boxes
set title "Input wave" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Hight" font "Times New Roman, 14"
set output "input.png"
plot "input.dat" with lines
set title "Mixed wave" font "Times New Roman, 14"
set xlabel "Frequency" font "Times New Roman, 14"
set ylabel "Hight" font "Times New Roman, 14"
set output "wave.png"
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

