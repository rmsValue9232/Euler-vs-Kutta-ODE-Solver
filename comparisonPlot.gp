# comparisonPlot.gp - GNUplot script to compare Euler and Kutta ODE solvers

set terminal png size 1080,720
set output './plots/comparison_plot.png'

set title "Forward Euler vs. Runge Kutta for step h = 0.1"
set xlabel "t"
set ylabel "y"
set grid

# Plot the data files, skipping the first row
plot './data/euler_with_11_points.txt' using 1:2 every ::1 with lines title 'Euler', \
     './data/kutta_with_11_points.txt' using 1:2 every ::1 with lines title 'Kutta'