open Revery;
open Revery.UI;
open Yojson.Safe;
open Core;
open App_Components;

module AppSettings = {
  let sidebarWidth = 250;
}

let buf = In_channel.read_all(
  Revery.Environment.getExecutingDirectory() ++ "app.settings.json"
);

let json_string = from_string(buf);
let app_title = json_string 
  |> Util.member("app") 
  |> Util.member("name") 
  |> Util.to_string;

let init = app => {
  let win = App.createWindow(
    ~createOptions={
      ...Window.defaultCreateOptions,
      maximized: true,
      icon: Some("logo.png")
    },
    app, 
    app_title
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
      backgroundColor(Color.hex("#252629")),
    ];

  let innerStyle = 
    Style.[
      position(`Absolute),
      top(0),
      left(0),
      right(0),
      bottom(0),
      flexDirection(`Row), 
      alignItems(`FlexEnd),
      backgroundColor(Color.hex("#2F3034"))
    ];

  let render = () =>
    <View style=Style.[
      position(`Absolute),
      bottom(0),
      top(0),
      left(0),
      right(0)
    ]>
      <Sidebar sidebarWidth={AppSettings.sidebarWidth}>
        <RegularButton />
      </Sidebar>
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
        
      </View>
    </View>;

  UI.start(win, render);
};

App.start(init);