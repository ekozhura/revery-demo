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
        backgroundColor(Color.rgba(1., 1., 1., 0.1)),
        border(~width=2, ~color=Colors.white),
        margin(16),
      ];

    let textHeaderStyle =
      Style.[
        color(Colors.white),
        fontFamily(Fonts.openSans),
        fontSize(20),
        margin(4),
      ];

    let textContent = "Click me: " ++ string_of_int(count);

    (hooks, <Clickable onClick=increment>
      <View style=wrapperStyle>
        <Text style=textHeaderStyle text=textContent />
      </View>
    </Clickable>);
  });