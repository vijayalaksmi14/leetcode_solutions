function calculateTotal(price, tax) {
  const total = price + price * tax;
  return total;
}
const user = {
  name: 'Alice',
  age: 30,
  hobbies: ['reading', 'coding'],
};
// console.log(calculateTotal(100, 0.08));