open Revery;
open Revery.UI;
open Revery.UI.Components;

let component = React.component("Sidebar");

let make = (~sidebarWidth, children: React.syntheticElement) =>
  component(hooks => {  
    (hooks, <ScrollView
        style=Style.[
          position(`Absolute),
          top(0),
          left(0),
          width(sidebarWidth),
          bottom(0),
          backgroundColor(Color.hex("#3B3E43")),
        ]>
        <View> children </View>
      </ScrollView>);
  });

let createElement = (
  ~sidebarWidth=100, 
  ~children, 
  ()) => make(~sidebarWidth, React.listToElement(children));