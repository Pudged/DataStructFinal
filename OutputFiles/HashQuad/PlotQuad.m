clc
close all
clear all

%% Data Read

insertA = readtable('insertTimesHashQuad_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertTimesHashQuad_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchTimesHashQuad_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchTimesHashQuad_B.csv');
searchB = searchB{:,1};


%% Plots

Iterations = linspace(0, 400, 400);

figure
plot(insertA, 'r');
hold on
plot(insertB, 'b');
title("Hash(Quadratic Probing) Insertion");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("Hash(Quadratic Probing) Search");
xlabel("Iteration")
ylabel("Time Avg");
legend("Data A", "Data B",'Location','northwest');
%% Data Read

insertA = readtable('insertCollisionsHashQuad_A.csv');
insertA = insertA{:,1};
insertB = readtable('insertCollisionsHashQuad_B.csv');
insertB = insertB{:,1};

searchA = readtable('searchCollisionsHashQuad_A.csv');
searchA = searchA{:,1};
searchB = readtable('searchCollisionsHashQuad_B.csv');
searchB = searchB{:,1};

%% Plots

Iterations = linspace(0, 400, 400);

figure
plot(insertA(1:395), 'r');
hold on
plot(insertB(1:395), 'b');
title("Hash(Quadratic Probing) Insertion Collisions");
xlabel("Iteration")
ylabel("# Collisions");
legend("Data A", "Data B",'Location','northwest');

figure

plot(searchA, 'r');
hold on
plot(searchB, 'b');
title("Hash(Quadratic Probing) Search Collisions");
xlabel("Iteration")
ylabel("# Collisions");
legend("Data A", "Data B",'Location','northwest');