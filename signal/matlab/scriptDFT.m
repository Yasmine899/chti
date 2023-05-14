clear all;
close all;

%% Paramètres
T = 0.25;               % Fenêtre d'observation
M=32;                   % Nombre d'échantillons dans la fenêtre


%% Paramètres déduits
Te = T/M;               % Période d'échantillonnage
Tsim = T-Te;            % Instant final de simulation
Fsin = 4 ;
%% Calculs préliminaires 


%% Lancement de simulink
out=sim("simDFT")

%% Visualisations temporelle
plot(out.sin_continu,'.-');
hold on;
plot(out.sin_echanti,'o');
grid on;

%% Calcul DFT


%% visualisation DFT
figure();


