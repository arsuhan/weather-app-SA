const apiKey = "32284042fed89cb9ab52ad2c862a8e28";
const apiUrl = "https://api.openweathermap.org/data/2.5/weather?units=metric&q=";

const searchBox = document.getElementById("searchBox");
const searchBtn = document.getElementById("searchBtn");

async function checkWeather(city) {
  try {
    const response = await fetch(apiUrl + city + `&appid=${apiKey}`);
    if (!response.ok) {
      alert("City not found ");
      return;
    }

    const data = await response.json();
    console.log(data);

    document.getElementById("city").textContent = data.name;
    document.getElementById("temp").textContent = Math.round(data.main.temp) + "°C";
    document.getElementById("humidity").textContent = data.main.humidity + "%";
    document.getElementById("wind").textContent = Math.round(data.wind.speed) + " km/h";
    document.getElementById("icon").src =
      "https://openweathermap.org/img/wn/" + data.weather[0].icon + "@2x.png";
  } catch (error) {
    console.error("Error fetching weather:", error);
    alert("Something went wrong ");
  }
}

// Search button click
searchBtn.addEventListener("click", () => {
  const city = searchBox.value.trim();
  if (city) {
    checkWeather(city);
    searchBox.value = "";
  } else {
    alert("Please enter a city name");
  }
});

// Press Enter to search
searchBox.addEventListener("keyup", (event) => {
  if (event.key === "Enter") {
    const city = searchBox.value.trim();
    if (city) {
      checkWeather(city);
      searchBox.value = "";
    } else {
      alert("Please enter a city name");
    }
  }
});
