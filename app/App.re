open Revery;
open Revery.UI;
open Revery.UI.Components;
open Yojson.Safe; 
open App_Components;

module AppSettings = {
  let sidebarWidth = 250;
}

let init = app => {
  let win = App.createWindow(
    app, 
    "hello world"
  );

  let containerStyle =
    Style.[
      position(`Absolute),
      justifyContent(`Center),
      alignItems(`Center),
      bottom(0),
      top(0),
      left(AppSettings.sidebarWidth),
      right(0),
      backgroundColor(Colors.black),
    ];

  let innerStyle = 
    Style.[
      position(`Absolute),
      top(0),
      left(0),
      right(0),
      bottom(0),
      flexDirection(`Row), 
      alignItems(`FlexEnd)
    ];

  let render = 
    <View style=Style.[
      position(`Absolute),
      bottom(0),
      top(0),
      left(0),
      right(0)
    ]>
      <ScrollView
        style=Style.[
          position(`Absolute),
          top(0),
          left(0),
          width(AppSettings.sidebarWidth),
          bottom(0),
          backgroundColor(Colors.darkSlateGray),
        ]>
        <View/>
      </ScrollView>
      <View style=containerStyle>
        <View style=innerStyle>
          <Text style=Style.[
            color(Colors.white),
            fontFamily(Fonts.openSans),
            fontSize(14),
            margin(4),
          ] text="text" />
          <Text style=Style.[
            color(Colors.white),
            fontFamily(Fonts.roboto),
            fontSize(14),
            margin(4),
          ] text="text2" />
        </View>
        <RegularButton />
      </View>
    </View>;

    let _ = UI.start(win, render);
    ();
};

App.start(init);