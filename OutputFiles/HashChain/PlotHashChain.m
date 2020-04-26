clc
close all
clear all

%% Data Read

insertA = readtable('insertTimesHashChain_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertTimesHashChain_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchTimesHashChain_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchTimesHashChain_B.csv');
searchB = searchB{:,1};


%% Plots

Iterations = linspace(0, 400, 400);

figure
plot(insertA, 'r');
hold on
plot(insertB, 'b');
title("Hash(Chaining) Insertion");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("Hash(Chaining) Search");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');
%% Data Read

insertA = readtable('insertCollisionsHashChain_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertCollisionsHashChain_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchCollisionsHashChain_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchCollisionsHashChain_B.csv');
searchB = searchB{:,1};

%% Plots

Iterations = linspace(0, 400, 400);

figure
plot(insertA(1:395), 'r');
hold on
plot(insertB(1:395), 'b');
title("Hash(Chaining) Insertion Collisions");
xlabel("Iteration")
ylabel("# Collisions");
legend("Data A", "Data B",'Location','northwest');

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("Hash(Chaining) Search Collisions");
xlabel("Iteration")
ylabel("# Collisions");
legend("Data A", "Data B",'Location','northwest');