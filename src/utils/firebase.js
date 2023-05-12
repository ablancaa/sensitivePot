//CONFIGURACIÓN DE FIREBASE

// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getDatabase } from "firebase/database";
import "firebase/auth";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyAq47EHEvsvaqfHTczfl5eaObErq857zs8",
  authDomain: "sensitivepot-d0ada.firebaseapp.com",
  projectId: "sensitivepot-d0ada",
  storageBucket: "sensitivepot-d0ada.appspot.com",
  messagingSenderId: "108383124629",
  appId: "1:108383124629:web:57100d4a065dde146bef9c",
  databaseURL: "https://sensitivepot-d0ada-default-rtdb.europe-west1.firebasedatabase.app/",
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const database = getDatabase();

//Utils
const auth = app.auth;
export { auth, app, firebaseConfig, database };
