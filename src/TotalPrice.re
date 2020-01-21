// let qty = 7;
// let price = 15;
// let total = qty * price;
// Js.log2("The total price is $", total);

// Does NOT compile because it is using the integer multiplication character * and price is a float
// let qty = 7;
// let price = 14.50;
// let total = qty * price;
// Js.log2("The total price is $", total);

//This compiles because we are using the FLOAT multiplication operand *. and both types are floats
// let qty = 7.0;
// let price = 14.50;
// let total = qty *. price;
// Js.log2("The total price is $", total);

//More explicit type declarartion, but less commonly used
let qty: int = 7;
let price: float = 14.50;
// If/Else keywords are expressions and not statements because you can bind the result of them to a variable. Both expressions must result in the same type
let discount =
  if (qty < 10) {
    0.05;
  } else {
    0.10;
  };
//Ternary version of above code
// let discount = (qty < 10) ? 0.05 : 0.10;
let total = float_of_int(qty) *. price;
let afterDiscount = total *. (1.0 -. discount);
Js.log2("Price before discount: $", total);
Js.log2("Price after discount: $", afterDiscount);

//the same thing as above using concatenation. However, this produces unexpected characters because Reason evaluates strings to ASCII and JS evaluates them to UNICODE
// Js.log("Prix avant réduction: " ++ Js.Float.toString(total) ++ " €");
// Js.log("Prix après réduction: " ++ Js.Float.toString(afterDiscount) ++ " €");

// This fixes that problem
// Js.log(
//   {js|Prix avant réduction: |js} ++ Js.Float.toString(total) ++ {js| €|js},
// );
// Js.log(
//   {js|Prix après réduction: |js}
//   ++ Js.Float.toString(afterDiscount)
//   ++ {js| €|js},
// );

// Its much shorter to use js string interpolation using the $ character before a variable
Js.log({j|Prix avant réduction: $total €|j});
Js.log({j|Prix après réduction: $afterDiscount €|j});

/* Missing else clause */
// let bad1 = if (qty < 10) { 0.05; };
/* if yields integer; else yields float */
// let bad2 =
//   if (qty < 10) {
//     0;
//   } else {
//     0.05;
//   };

//The sqrt and abs_float functions are built into the Pervasives module
let result = sqrt(abs_float(-3.75));
Js.log2("The sqrt is ", result);

//Also, JavaScript functions are available through Js.----
let r = 7.0;
let area = Js.Math._PI *. r *. r;
Js.log2("The area is ", area);

//  the js| allows multi-line strings
let poem = {js|The boy stood on the burning deck, Whence all but he had fled;
The flames that lit the battle’s wreck...|js};
Js.log(poem);

let temp: float = 5.0;
let wind_speed: float = 20.0;
// ** is the exponential operand. So, it reads wind_speed to the 0.16 power
let wind_chill = 13.12 +. (0.6215 *. temp) -. (11.37 *. wind_speed ** 0.16) +. (0.3965 *. temp *. wind_speed ** 0.16);

Js.log({j|At temperature $temp degrees C and wind speed $wind_speed,
          the wind chill temperature is $wind_chill|j});


