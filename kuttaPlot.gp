# kuttaPlot.gp - GNUplot script to plot Runge Kutta solution for different step sizes

set terminal png size 1080,720
set output './plots/kutta_step.png'

set title "Runge Kutta Step Size Variation Accuracy Dependency"
set xlabel "t"
set ylabel "y"
set grid

# Plot the data files, skipping the first row
plot './data/kutta_with_11_points.txt' using 1:2 every ::1 with lines title 'step h = 0.1', \
     './data/kutta_with_101_points.txt' using 1:2 every ::1 with lines title 'step h = 0.01', \
     './data/kutta_with_1001_points.txt' using 1:2 every ::1 with lines title 'step h = 0.001'
