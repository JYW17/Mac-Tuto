LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY HB_MEARLY_MACHINE IS
PORT(
    RESETN : IN STD_LOGIC;
    X : IN STD_LOGIC;
    Y : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
);
END HB_MEARLY_MACHINE;

ARCHITECTURE HB OF HB_MEARLY_MACHINE IS

TYPE STATE_TYPE IS (S0,S1,S2);
SIGNAL CURRENT_STATE : STATE_TYPE;

BEGIN

PROCESS(RESETN,X,Y)
BEGIN
    IF RESETN = '1' THEN
        CURRENT_STATE <= S0;
    ELSIF X'EVENT AND X = '0' THEN
        CASE CURRENT_STATE IS
            WHEN S0 =>
                IF Y = '00' THEN
                    CURRENT_STATE <= S2;
                END IF;
            WHEN S1 =>
                IF Y = '00' THEN
                    CURRENT_STATE <= S0;
                END IF;
            WHEN S2 =>
                IF Y = '01' THEN
                    CURRENT_STATE <= S0;
                END IF;
        END CASE;
    ELSIF X'EVENT AND X = '1' THEN
        CASE CURRENT_STATE IS
            WHEN S0 =>
                IF Y = '10' THEN
                    CURRENT_STATE <= S1;
                END IF;
            WHEN S1 =>
                IF Y = '10' THEN
                    CURRENT_STATE <= S2;
                END IF;
            WHEN S2 =>
                IF Y = '01' THEN
                    CURRENT_STATE <= S1;
                END IF;
    END IF;
END PROCESS;
END HB;
