clc
close all
clear all

%% Data Read

insertA = readtable('insertTimesLL_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertTimesLL_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchTimesLL_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchTimesLL_B.csv');
searchB = searchB{:,1};


%% Plots

Iterations = linspace(0, 399, 399);

figure
plot(insertA, 'r');
hold on
plot(insertB, 'b');
title("LL Insertion");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B");

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("LL Search");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B");