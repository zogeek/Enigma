/* eslint-disable react/prop-types */

export default function SearchForm({ searchTerm, onSearchInput }) {
    const handleChange = (e) => {
        onSearchInput(e);
    };

    return (
        <form>
            <label htmlFor="search"> Search:</label>
            <input
                type="search"
                name="search"
                id="search"
                value={searchTerm}
                onChange={handleChange}
            />
            <p>Search for {searchTerm}</p>
        </form>
    );
}
