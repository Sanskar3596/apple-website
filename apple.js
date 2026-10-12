const hamburger = document.getElementById("hamburger");
const navItems = document.getElementById("navItems");
 
hamburger.addEventListener("click", () => {
    navItems.classList.toggle("open");
});
 
// ============================================================
// 2) SEARCH BOX TOGGLE + LIVE FILTER
// ============================================================
const searchIcon = document.getElementById("searchIcon");
const searchBox = document.getElementById("searchBox");
const searchInput = document.getElementById("searchInput");
const closeSearch = document.getElementById("closeSearch");
const searchResults = document.getElementById("searchResults");
 
// list of "products" we can search through (name + short note)
const catalog = [
    { name: "iPhone 17 Pro", note: "Starting at ₹1,34,900" },
    { name: "MacBook Pro", note: "Starting at ₹1,69,900" },
    { name: "MacBook Air", note: "Starting at ₹99,900" },
    { name: "iPad", note: "Starting at ₹29,900" },
    { name: "Apple Watch", note: "Starting at ₹31,900" },
    { name: "AirPods Max", note: "Starting at ₹59,900" },
    { name: "AirTag", note: "Starting at ₹3,190" },
    { name: "HomePod", note: "Starting at ₹22,900" },
];
 
searchIcon.addEventListener("click", () => {
    const isOpen = searchBox.style.display === "flex";
    searchBox.style.display = isOpen ? "none" : "flex";
    searchResults.innerHTML = "";
    if (!isOpen) searchInput.focus();
});
 
closeSearch.addEventListener("click", () => {
    searchBox.style.display = "none";
    searchInput.value = "";
    searchResults.innerHTML = "";
});
 
searchInput.addEventListener("input", () => {
    const term = searchInput.value.trim().toLowerCase();
    searchResults.innerHTML = "";
 
    if (term === "") return;
 
    const matches = catalog.filter(item =>
        item.name.toLowerCase().includes(term)
    );
 
    if (matches.length === 0) {
        searchResults.innerHTML = `<div>No results for "${searchInput.value}"</div>`;
        return;
    }
 
    matches.forEach(item => {
        const row = document.createElement("div");
        row.textContent = `${item.name} — ${item.note}`;
        searchResults.appendChild(row);
    });
});
 
// ============================================================
// 3) ADD TO BAG (click a category picture to "add" it)
// ============================================================
const bagCount = document.getElementById("bagCount");
const toast = document.getElementById("toast");
let bagTotal = 0;
 
document.querySelectorAll(".porductbar").forEach(item => {
    item.addEventListener("click", () => {
        bagTotal++;
        bagCount.textContent = bagTotal;
        bagCount.style.display = "block";
 
        const productName = item.getAttribute("data-name");
        showToast(`${productName} added to bag`);
    });
});
 
function showToast(message) {
    toast.textContent = message;
    toast.classList.add("show");
    clearTimeout(showToast.timer);
    showToast.timer = setTimeout(() => {
        toast.classList.remove("show");
    }, 2000);
}
 
// ============================================================
// 4) STICKY NAVBAR SHADOW + BACK-TO-TOP BUTTON ON SCROLL
// ============================================================
const navbar = document.getElementById("navbar");
const backToTop = document.getElementById("backToTop");
 
window.addEventListener("scroll", () => {
    if (window.scrollY > 10) {
        navbar.classList.add("scrolled");
    } else {
        navbar.classList.remove("scrolled");
    }
 
    if (window.scrollY > 500) {
        backToTop.style.display = "flex";
    } else {
        backToTop.style.display = "none";
    }
});
 
backToTop.addEventListener("click", () => {
    window.scrollTo({ top: 0, behavior: "smooth" });
});
 
// ============================================================
// 5) STAGGERED FADE-IN FOR "THE LATEST" PHOTOS
// ============================================================
document.querySelectorAll(".photo img").forEach((img, index) => {
    img.style.animationDelay = `${index * 0.15}s`;
});
 