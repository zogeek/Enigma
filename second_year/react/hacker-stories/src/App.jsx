import React, { useEffect } from "react";
import SearchForm from "./components/SearchForm";
import List from "./components/List";

function App() {
    const stories = [
        {
            id: 0,
            title: "React",
            url: "https://reactjs.org/",
            author: "Jordan Walke",
            num_comments: 3,
            points: 4,
        },
        {
            id: 1,
            title: "Redux",
            url: "https://redux.js.org/",
            author: "Dan Abramov, Andrew Clark",
            num_comments: 2,
            points: 5,
        },
    ];

    const [searchTerm, setSearchTerm] = React.useState(
        localStorage.getItem("search") || ""
    );

    const searchStories = stories.filter((story) =>
        story.title.toLowerCase().includes(searchTerm.toLowerCase())
    );

    const handleSearch = (e) => {
        setSearchTerm(e.target.value);
    };

    useEffect(() => {
        localStorage.setItem("search", searchTerm);
    }, [searchTerm]);

    return (
        <div>
            <h1>My Hacker Stories</h1>
            <SearchForm searchTerm={searchTerm} onSearchInput={handleSearch} />
            <hr />
            <List list={searchStories} />
        </div>
    );
}

export default App;