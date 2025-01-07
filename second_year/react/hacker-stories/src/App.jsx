import React, { useEffect, useReducer } from "react";
import axios from "axios";
import SearchForm from "./components/SearchForm";
import List from "./components/List";
import {
    storiesreducer,
    initialState,
    STORIES_FETCH_INIT,
    STORIES_FETCH_SUCCESS,
    STORIES_FETCH_FAILURE,
    REMOVE_STORY,
} from "./storiesReducer.js";
import "./App.css";
const API_ENDPOINT = "https://hn.algolia.com/api/v1/search?query=";

function App() {
    const [stories, dispatchstories] = useReducer(storiesreducer, initialState);
    const [searchTerm, setSearchTerm] = React.useState(
        localStorage.getItem("search") || ""
    );

    const handleSearchInput = (e) => {
        setSearchTerm(e.target.value);
    };

    function handleRemoveStory(objectID) {
        dispatchstories({
            type: REMOVE_STORY,
            payload: { objectID },
        });
    }

    useEffect(() => {
        dispatchstories({ type: STORIES_FETCH_INIT });
        axios(`${API_ENDPOINT}${searchTerm}`)
            .then(({ data }) => {
                dispatchstories({
                    type: STORIES_FETCH_SUCCESS,
                    payload: data,
                });
            })
            .catch((err) => {
                console.log(err);
                dispatchstories({ type: STORIES_FETCH_FAILURE });
            });
    }, [searchTerm]);

    useEffect(() => {
        localStorage.setItem("search", searchTerm);
    }, [searchTerm]);

    return (
        <div className="app-container">
            <h1>My Hacker Stories</h1>
            <SearchForm
                searchTerm={searchTerm}
                onSearchInput={handleSearchInput}
            />
            <hr />
            {stories.isError && <p>Something went wrong ...</p>}
            {stories.isLoading ? (
                <div className="spinner"></div>
            ) : (
                <List
                    list={stories.data.hits}
                    onRemoveItem={handleRemoveStory}
                />
            )}
        </div>
    );
}

export default App;
