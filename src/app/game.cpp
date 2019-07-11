#include "game.h"

Game::Game()
{
    m_buffers = new Buffers;
    m_configData = new ConfigData;

    //InitPlayerFigures;
    //InitEnemyFigures;
}

Game::~Game()
{
    delete m_buffers;
    delete m_configData;
}

void Game::start()
{
    // Intro

    //do {
        // The game
    //} while(!m_buffers->quitGame());
    /*

{$IFDEF MENU}
  repeat
{$ENDIF}

    ClearVGAMem;

    InitPlayerFigures;
    InitEnemyFigures;

    EndGame := FALSE;
  {$IFDEF MENU}
    Intro;
  {$ENDIF}

    Randomize;

    with Data do
    begin
      if NumPlayers = 2 then
        if Progress [plMario] > Progress [plLuigi] then
          Progress [plLuigi] := Progress [plMario]
        else
          Progress [plMario] := Progress [plLuigi];

      Lives [plMario] := 3;
      Lives [plLuigi] := 3;
      Coins [plMario] := 0;
      Coins [plLuigi] := 0;
      Score [plMario] := 0;
      Score [plLuigi] := 0;
      Mode [plMario] := mdSmall;
      Mode [plLuigi] := mdSmall;
    end;

    repeat
      if Data.NumPlayers = 1 then
        Data.Lives [plLuigi] := 0;
      for CurPlayer := plMario to Data.NumPlayers - 1 do
      begin
        if not (EndGame or QuitGame) then
          if Data.Lives [CurPlayer] >= 1 then
          begin
            with Data do
            begin
              Turbo := (Progress [CurPlayer] >= NUM_LEV);
              if Progress [CurPlayer] > LAST_LEV then
                Progress [CurPlayer] := NUM_LEV;
            end;
         {$IFDEF MENU}
            ShowPlayerName (CurPlayer);
         {$ENDIF}
            case Data.Progress [CurPlayer] mod NUM_LEV of
              0: Passed := PlayWorld ('x', '1', @Level_1a^, @Options_1a^, @Opt_1a^,
                   @Level_1b^, @Options_1b^, @Options_1b^, CurPlayer);
              1: Passed := PlayWorld ('x', '2', @Level_2a^, @Options_2a^, @Opt_2a^,
                   @Level_2b^, @Options_2b^, @Options_2b^, CurPlayer);
              2: Passed := PlayWorld ('x', '3', @Level_3a^, @Options_3a^, @Opt_3a^,
                   @Level_3b^, @Options_3b^, @Options_3b^, CurPlayer);
              3: Passed := PlayWorld ('x', '4', @Level_5a^, @Options_5a^, @Opt_5a^,
                   @Level_5b^, @Options_5b^, @Options_5b^, CurPlayer);
              4: Passed := PlayWorld ('x', '5', @Level_6a^, @Options_6a^, @Opt_6a^,
                   @Level_6b^, @Options_6b^, @Options_6b^, CurPlayer);
              5: Passed := PlayWorld ('x', '6', @Level_4a^, @Options_4a^, @Opt_4a^,
                   @Level_4b^, @Options_4b^, @Options_4b^, CurPlayer);
              else
                EndGame := TRUE;
            end;

            if Passed then
              Inc (Data.Progress [CurPlayer]);
            if QuitGame then
            begin
              EndGame := TRUE;
            {$IFDEF MENU}
              QuitGame := FALSE;
            {$ENDIF}
            end;
          end;

      end;
    until EndGame or QuitGame or
      (Data.Lives [plMario] + Data.Lives [plLuigi] = 0);

    if GameNumber <> -1 then
      Config.Games[GameNumber] := Data;

{$IFDEF MENU}
  until QuitGame;
{$ENDIF}
  WriteConfig;


  */
}
