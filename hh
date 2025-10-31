// // Replace with your OpenWeatherMap API key
// const apiKey = "32284042fed89cb9ab52ad2c862a8e28";
// const apiUrl =
//   "https://api.openweathermap.org/data/2.5/weather?units=metric&q=";

// const searchBox = document.getElementById("searchBox");
// const searchBtn = document.getElementById("searchBtn");

// async function checkWeather(city) {
//   const response = await fetch(apiUrl + city + `&appid=${apiKey}`);
//   if (response.status === 404) {
//     alert("City not found!");
//     return;
//   }

//   const data = await response.json();
//   console.log(data);

//   // Update UI
//   document.getElementById("city").textContent = data.name;
//   document.getElementById("temp").textContent = Math.round(data.main.temp) + "°C";
//   document.getElementById("humidity").textContent = data.main.humidity + "%";
//   document.getElementById("wind").textContent = Math.round(data.wind.speed) + " km/h";
//   document.getElementById("icon").src = "https://openweathermap.org/img/wn/" + data.weather[0].icon + "@2x.png";
// }

// searchBtn.addEventListener("click", () => {
//   const city = searchBox.value.trim();
//   if (city !== "") {
//     checkWeather(city);
//   } else {
//     alert("Please enter a city name!");
//   }
// });


const apiKey = "32284042fed89cb9ab52ad2c862a8e28";
const apiUrl = "https://api.openweathermap.org/data/2.5/weather?units=metric&q=";

const searchBox = document.getElementById(".searchBox");
const searchBtn = document.getElementById(".search Button");

async function checkWeather() {
  const response = await fetch(apiUrl + city + `&appid=${apiKey}`);
  let data = await response.json();
  console.log(data);
  document.getElementById("city").textContent = data.name;
  document.getElementById("temp").textContent = Math.round(data.main.temp) + "°c";
  document.getElementById("humidity").textContent = data.main.humidity + "%";
  document.getElementById("wind").textContent = data.wind.speed + " km/h";
  document.getElementById("icon").src = "https://openweathermap.org/img/wn/" + data.weather[0].icon + ".png";
}

searchBox.addEventListener("keyup", (event) => {
    if (event.key === "Enter") {
        const city = searchBox.value.trim();
        checkWeather(city);
    }
  });

// searchBtn.addEventListener("click", () => {
//     console.log("click");
//     // const city = searchBox.value;
//     // checkWeather(city);
//     const city = searchBox.value.trim();
//     // const city = searchBox.value.trim();
//     // checkWeather(searchBox.value)
// })
