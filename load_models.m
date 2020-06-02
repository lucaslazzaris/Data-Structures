%**************************************************************************
%        Load Control  
%
%  Autor: Roberto Andrich
%  Data de Criação: 14/10/2014
%  Data de Modificação:
%
%**************************************************************************
function [load, debug] = load_models(th)
    %**********************************************************************
    %Choose the appropriated load Configuration
    %**********************************************************************
    %Load_Type    :  1 - Fixed Load
    %                2 - Compressor Load
    load_type = 2;
    
    %Fixed Load configuration
    torq = 2*0.0980665;      %Torque in N.m or (kgf.cm)*0.0980665
    
    %Compressor Load Configuration
    Ts =  -00;        %Suction temperature in celcius degrees
    Td =   60;        %Discharge temperature in celcius degrees

    %**********************************************************************
    %Variables
    %**********************************************************************
    %General vars
    persistent load_out;     
    
    %Compressor variables
    persistent Rexc;        %eccentricity
    persistent Dpist;       %piston diameter
    persistent Spist;       %piston area
    persistent Vm;          %dead volume
    persistent ngas;        %gas constant
    persistent Ps;          %Suction pressure
    persistent Pd;          %Discharge pressure
    persistent Vc;          %Cylinder volume
    persistent Vc_old;      %previous cylinder volume
    persistent dVc;         %cyclinder volume variation
    persistent Vmax;        %Maximum  cylinder volume

    %initializing persistent vars
    if isempty(load_out)
        %General vars
        load_out = torq;
        
        %Compressor variables init (VEMX9C,R600a)
        Rexc=10e-3;          %m
        Dpist=24e-3;         %m
        Spist=Dpist^2*pi/4;  %m^2      
        Vm=120e-9;           %m^3
        ngas=1.1;
        Ps=T2P(Ts,2)*1e5;    %Pa
        Pd=T2P(Td,2)*1e5;    %Pa
        dVc = 0;
        Vc = (cos(th+pi/6)+1)*Rexc*Spist+Vm; %init. cylinder volume
        Vc_old = Vc;
        Vmax = (1+1)*Rexc*Spist+Vm;          %max volume when cos(th)=1       

    end

    %**********************************************************************
    %Simplified Compression
    %**********************************************************************
	%
	Vc=(cos(th+pi/6)+1)*Rexc*Spist+Vm;         
	dVc = Vc - Vc_old;                         
	Vc_old = Vc;
	
	if (dVc > 0)
		if (Vc < Vm*((Pd/Ps)^(1/ngas)))
			Pc = Pd*((Vm/Vc)^ngas);
		else
			Pc = Ps;
		end
	else
		if (Vc > Vmax*((Ps/Pd)^(1/ngas)))
			Pc = Ps*((Vmax/Vc)^ngas);
		else
			Pc = Pd;
		end
	end        
	tcil=sin(th+pi/6)*Rexc*(Pc-Ps)*Spist; %Cylinder Torque
        
    %**********************************************************************
    %Selecting the output load
    %**********************************************************************
    if (load_type == 1)
        load_out = torq;
    else
        load_out = tcil;
    end

    %**********************************************************************
    %Update Output 
    %**********************************************************************
    load = load_out;
    debug = tcil;
    
end

