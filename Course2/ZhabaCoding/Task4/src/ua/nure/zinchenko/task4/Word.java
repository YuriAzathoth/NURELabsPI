package ua.nure.zinchenko.task4;

import java.util.Objects;

public class Word implements Comparable<Word> {
    private String content;
    private int freq;

    Word(String content, int freq) {
        this.content = content;
        this.freq = freq;
    }

    String getContent() {
        return content;
    }

    int getFrequency() {
        return freq;
    }

    @Override
    public boolean equals(Object object) {
        if (this == object){
            return true;
        }
        if (object == null){
            return false;
        }
        if (getClass() != object.getClass()){
            return false;
        }
        Word word = (Word) object;
        return Objects.equals(content, word.getContent())
                && Objects.equals(freq, word.getFrequency());
    }

    @Override
    public int compareTo(Word word) {
        if(freq > word.getFrequency()){
            return 1;
        }else if(freq == word.getFrequency()){
            return content.compareTo(word.getContent());
        }else{
            return -1;
        }
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}
