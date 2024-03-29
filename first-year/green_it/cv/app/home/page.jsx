import Image from "next/image";
import Link from "next/link";

export default function Home() {
  return (
    <div
      style={{
        display: "flex",
        height: "100vh",
        justifyContent: "center",
        alignItems: "center",
      }}
    >
      <nav
        className="text-xs font-size: 0.75rem;"
        style={{
          position: "absolute",
          top: 50,
          right: 100,
          display: "flex",
        }}
      >
        <ul style={{ display: "flex", listStyle: "none" }}>
          <li style={{ marginRight: "50px" }}>
            <Link href="/">Accueil</Link>
          </li>
          <li>
            <Link href="/about">À propos</Link>
          </li>
        </ul>
      </nav>

      <main
        style={{
          display: "flex",
          justifyContent: "space-between",
          width: "100%",
        }}
      >
        <div style={{ textAlign: "left", justifyContent: "flex-start" }}>
          <h1>Bienvenue sur ma page Next.js!</h1>
          <p>
            Ceci est un exemple de page avec une barre de navigation, du texte
            et une image.
          </p>
        </div>
        <Image
          src="/vercel.svg" // Remplacez ceci par le chemin de votre image
          alt="Vercel Logo"
          width={500}
          height={300}
        />
      </main>
    </div>
  );
}
