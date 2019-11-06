open Revery;
open Revery.UI;
open Revery.UI.Components;

let component = React.component("RegularButton");

let createElement = (~children as _, ()) =>
  component(hooks => {
    
    let (count, setCount, hooks) =
      React.Hooks.state(0, hooks);

    let increment = () => setCount(count + 1);

    let wrapperStyle =
      Style.[
        backgroundColor(Colors.white),
        border(~width=1, ~color=Colors.white),
        borderRadius(5.),
        margin(16),
      ];

    let innerStyle =
      Style.[
        backgroundColor(Colors.black),
        border(~width=1, ~color=Colors.black),
        borderRadius(5.),
        margin(1)
      ];

    let textHeaderStyle =
      Style.[
        color(Colors.white),
        fontFamily(Fonts.openSans),
        fontSize(20),
        margin(14),
      ];

    let textContent = "Click me: " ++ string_of_int(count);

    (hooks, <Clickable onClick=increment>
      <View style=wrapperStyle>
        <View style=innerStyle>
          <Text style=textHeaderStyle text=textContent />
        </View>
      </View>
    </Clickable>);
  });