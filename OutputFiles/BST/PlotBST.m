clc
close all
clear all

%% Data Read

insertA = readtable('insertTimesBST_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertTimesBST_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchTimesBST_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchTimesBST_B.csv');
searchB = searchB{:,1};


%% Plots

Iterations = linspace(0, 400, 400);

figure
plot(insertA, 'r');
hold on
plot(insertB, 'b');
title("BST Insertion");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("BST Search");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');