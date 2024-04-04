import Image from "next/image";
import Link from "next/link";
import "./page.module.css";

export default function Home() {
  return (
    <div className="flex items-center justify-evenly h-screen">
      <nav className="fixed top-0 right-0 mr-4 flex justify-center items-center">
        <ul className="flex space-x-4">
          <li>
            <Link
              href="/"
              className="no-underline hover:underline text-decoration-color-[#224061]"
            >
              Accueil
            </Link>
          </li>
          <li>
            <Link
              href="/about"
              className="no-underline hover:underline text-decoration-color-[#224061]"
            >
              À propos
            </Link>
          </li>
        </ul>
      </nav>

      <main className="flex items-center justify-center w-full">
        <div className="flex items-center justify-around space-x-10">
          <div className="text-left flex-start">
            <h1>Bienvenue sur ma page Next.js!</h1>
            <p>
              Ceci est un exemple de page avec une barre de navigation, du texte
            </p>
          </div>
          <Image
            src="/free-nature-images.jpg"
            alt="Image of the Vercel Logo"
            width={500}
            height={300}
          />
        </div>
      </main>
    </div>
  );
}
