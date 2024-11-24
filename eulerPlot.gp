# eulerPlot.gp - GNUplot script to plot Forward Euler solution for different step sizes

set terminal png size 1080,720
set output './plots/euler_step.png'

set title "Forward Euler Step Size Variation Accuracy Dependency"
set xlabel "t"
set ylabel "y"
set grid

# Plot the data files, skipping the first row
plot './data/euler_with_11_points.txt' using 1:2 every ::1 with lines title 'step h = 0.1', \
     './data/euler_with_101_points.txt' using 1:2 every ::1 with lines title 'step h = 0.01', \
     './data/euler_with_1001_points.txt' using 1:2 every ::1 with lines title 'step h = 0.001'
