clc
close all
clear all

%% Data Read

insertA = readtable('insertTimesHashLin_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertTimesHashLin_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchTimesHashLin_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchTimesHashLin_B.csv');
searchB = searchB{:,1};


%% Plots

Iterations = linspace(0, 400, 400);

figure
plot(insertA(1:395), 'r');
hold on
plot(insertB(1:395), 'b');
title("Hash(Linear Probing) Insertion");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("Hash(Linear Probing) Search");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');

%% Data Read

insertA = readtable('insertCollisionsHashLin_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertCollisionsHashLin_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchCollisionsHashLin_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchCollisionsHashLin_B.csv');
searchB = searchB{:,1};

%% Plots

Iterations = linspace(0, 400, 400);

figure
plot(insertA(1:395), 'r');
hold on
plot(insertB(1:395), 'b');
title("Hash(Linear Probing) Insertion Collisions");
xlabel("Iteration")
ylabel("# Collisions");
legend("Data A", "Data B",'Location','northwest');

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("Hash(Linear Probing) Search Collisions");
xlabel("Iteration")
ylabel("# Collisions");
legend("Data A", "Data B",'Location','northwest');