
// Demo uses 78 Bytes.

void DemoApp_Start()
{
  // large block of text
  tft.fillScreen(ST7735_BLACK);
  testdrawtextlorem(ST7735_WHITE);
  delay(1000);

  // tft print function!
  tftPrintTest();
  delay(4000);

  // a single pixel
  tft.drawPixel(tft.width() / 2, tft.height() / 2, ST7735_GREEN);
  delay(500);

  // line draw test
  testlines(ST7735_YELLOW);
  delay(500);

  // optimized lines
  testfastlines(ST7735_RED, ST7735_BLUE);
  delay(500);

  testdrawrects(ST7735_GREEN);
  delay(500);

  testfillrects(ST7735_YELLOW, ST7735_MAGENTA);
  delay(500);

  tft.fillScreen(ST7735_BLACK);
  testfillcircles(10, ST7735_BLUE);
  testdrawcircles(10, ST7735_WHITE);
  delay(500);

  testroundrects();
  delay(500);

  testtriangles();
  delay(500);

  testdrawallchars();

  while (true) {
    uint8_t flag = GetControllerState();
    if (flag & B_BUTTON) {
      break;
    }
  }
}

void Calculator_Start()
{
  CurrentApplication = CURAPP_CALCULATOR;
  calculator_main();
}

void Notepad_Start()
{
  //  dlg_isShown = true;
  //  dlg_responsePositive = false;
  //  dlg_text1 = "Hello, world! This is";
  //  dlg_text2 = "supposed to be Notepad!";
  //  dlg_text3 = "Please click OK/Cancel.";
  //  dlg_caption="NOTEPAD.EXE";
  //  dlg_option1 = "  OK   ";
  //  dlg_option2 = "Cancel ";
  //  dlg_type = DLGTYPE_WELCOME;
  //  DrawDialog();

  CurrentApplication = CURAPP_NOTEPAD;
  // Press B to exit.
  // Press A to press key, and D-Pad to select.
  notepad_main();
}

void CLI_Start()
{
  CurrentApplication = CURAPP_CLI;
  cli_main();
}

void GamePadTest_Start()
{
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  while (true) {
    // 219
    uint8_t flag = GetControllerState();
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(0, 0);
    if (flag & UP_BUTTON) {
      tft.setTextColor(TFT_MAGENTA);
    }
    tft.print(' ');
    tft.print((char)BLOCK_CHARACTER);
    tft.print('\n');
    tft.setTextColor(TFT_WHITE);
    if (flag & LEFT_BUTTON) {
      tft.setTextColor(TFT_MAGENTA);
    }
    tft.print((char)BLOCK_CHARACTER);

    tft.print(' ');
    tft.setTextColor(TFT_WHITE);
    if (flag & RIGHT_BUTTON) {
      tft.setTextColor(TFT_MAGENTA);
    }
    tft.print((char)BLOCK_CHARACTER);
    tft.print(F("      "));

    tft.setTextColor(TFT_WHITE);
    if (flag & A_BUTTON) {
      tft.setTextColor(TFT_MAGENTA);
    }
    tft.print((char)BLOCK_CHARACTER);
    tft.print('\n');

    tft.print(' ');
    tft.setTextColor(TFT_WHITE);
    if (flag & DOWN_BUTTON) {
      tft.setTextColor(TFT_MAGENTA);
    }
    tft.print((char)BLOCK_CHARACTER);

    tft.print(F("     "));
    tft.setTextColor(TFT_WHITE);
    if (flag & B_BUTTON) {
      tft.setTextColor(TFT_MAGENTA);
    }
    tft.print((char)BLOCK_CHARACTER);
    tft.setTextColor(TFT_WHITE);
  }
}
